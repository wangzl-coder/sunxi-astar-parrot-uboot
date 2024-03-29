#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include "pinctrl_sunxi.h"
#include <asm/gpio.h>
#include <dm/device-internal.h>



#ifdef CONFIG_SUNXI_PINCTRL_FULL
static int pinctrl_sunxi_set_state(struct udevice *dev, struct udevice *config)
{
    SUNXI_PINCTRL_DEBUG("set state dev->name is %s ,config->name is %s \r\n",
                dev->name, config->name);

    return 0;
}
#else

/**
 * Returns the name of a GPIO bank
 *
 * GPIO banks are named A, B, C, ...
 *
 * @bank:	Bank number (0, 1..n-1)
 * @return allocated string containing the name
 */
static char *gpio_bank_name(int bank)
{
	char *name;

	name = malloc(3);
	if (name) {
		name[0] = 'P';
		name[1] = 'A' + bank;
		name[2] = '\0';
	}

	return name;
}

/**
 * We have a top-level GPIO device with no actual GPIOs. It has a child
 * device for each Sunxi bank.
 */
int gpio_sunxi_bind(struct udevice *parent)
{
	struct sunxi_gpio_soc_data *soc_data =
		(struct sunxi_gpio_soc_data *)dev_get_driver_data(parent);
	struct sunxi_gpio_platdata *plat = parent->platdata;
	struct sunxi_gpio_reg *ctlr;
	int bank, ret;

	/* If this is a child device, there is nothing to do here */
	if (plat)
		return 0;

	ctlr = (struct sunxi_gpio_reg *)devfdt_get_addr(parent);
	for (bank = 0; bank < soc_data->no_banks; bank++) {
		struct sunxi_gpio_platdata *plat;
		struct udevice *dev;

		plat = calloc(1, sizeof(*plat));
		if (!plat)
			return -ENOMEM;
		plat->regs = &ctlr->gpio_bank[bank];
		plat->bank_name = gpio_bank_name(soc_data->start + bank);
		plat->gpio_count = SUNXI_GPIOS_PER_BANK;

		ret = device_bind(parent, &gpio_sunxi,
					plat->bank_name, plat, -1, &dev);
		if (ret)
			return ret;
		dev_set_of_offset(dev, dev_of_offset(parent));
	}

	return 0;
}


static int sunxi_get_pins_by_name(const char *pin_name, unsigned int *bank, unsigned int *bank_pins)
{
	int bank_index;
	int pins_bank;
	char *eptr;

	if(!pin_name)
		return -1;
	
	if(!pin_name && *pin_name != 'P' && *pin_name != 'p')
		return -1;

	pin_name++;

	if(!pin_name && *pin_name < 'A')
		return -1;
	
	bank_index = *pin_name - (*pin_name > 'a' ? 'a' : 'A');

	pin_name ++;

	if(!pin_name)
		return -1;
	
	pins_bank = simple_strtol(pin_name, &eptr, 10);
	
	if(!pin_name || *eptr || pins_bank > 32)
		return -1;

	*bank = bank_index;
	*bank_pins = pins_bank;
	return 0;
}

static int pinctrl_sunxi_bank_funcVal(const char *pins_name, const char *func,  
		struct sunxi_pins_mux *pin_mux)
{
	int func_val = -1;
	int i = 0xf;

	while(i--)
	{
		if(0 == strcmp("disable", pin_mux->pin_func))
			break;
		
		if(0 == strcmp(func, pin_mux->pin_func))
		{
			SUNXI_PINCTRL_DEBUG("set pins %s to mux val %d \r\n",pins_name, pin_mux->reg_val);
			func_val = pin_mux->reg_val;
			break;
		}
		pin_mux ++;
	}

	return func_val;
}

static int pinctrl_sunxi_pins_cfg(const char *pins_name, const char *func, 
			struct sunxi_pinctrl_desc pins_desc)
{
	int func_val;
	
	func_val =  pinctrl_sunxi_bank_funcVal(pins_name, func,pins_desc.pin_mux);
	if(func_val == -1)
	{
		printf("sunxi pinctrl : get func val for %s--%s error \r\n",pins_name,func);
		return -EINVAL;
	}
	sunxi_gpio_set_cfgpin(pins_desc.n_pin, func_val);
	
	if(pins_desc.pull_cfg == SUNXI_GPIO_PULL_UP || 
		pins_desc.pull_cfg == SUNXI_GPIO_PULL_DOWN ||
		pins_desc.pull_cfg == SUNXI_GPIO_PULL_DISABLE)
	{
		SUNXI_PINCTRL_DEBUG("set pull %d for pins %s \r\n", pins_desc.pull_cfg, pins_name);
		sunxi_gpio_set_pull(pins_desc.n_pin, pins_desc.pull_cfg);
	}

	if(pins_desc.multi_drv == SUNXI_PINCTRL_10_MA ||
		pins_desc.multi_drv == SUNXI_PINCTRL_20_MA ||
		pins_desc.multi_drv == SUNXI_PINCTRL_30_MA ||
		pins_desc.multi_drv == SUNXI_PINCTRL_40_MA )
	{
		SUNXI_PINCTRL_DEBUG("set multi_dev %d for pins %s \r\n", pins_desc.multi_drv, pins_name);
		sunxi_gpio_set_drv(pins_desc.n_pin, pins_desc.multi_drv);
	}

	return 0;
}

static int pinctrl_sunxi_set_state_simple(struct udevice *dev, struct udevice *periph)
{
	const fdt32_t *list;
	uint32_t phandle;
	int size, i, offset, pins_count, name_len;
	const char *pins_name;
	const void *fdt = gd->fdt_blob;
	struct pinctrl_sunxi_priv *priv = dev_get_priv(dev);
	const char *function;
	int ret;
	u32 bank;
	u32 bank_pins;
	int multi_drv = 0;
    struct sunxi_pins_bank *curr_bank = NULL;
    struct sunxi_pinctrl_desc *curr_pinsdesc = NULL;

	SUNXI_PINCTRL_DEBUG("set state simple dev->name is %s , periph->name is %s \r\n",
				dev->name, periph->name);

	list = fdt_getprop(fdt, dev_of_offset(periph), "pinctrl-0", &size);

	if(!list){
		return -EINVAL;
	}
	for(i = 0; i< size/sizeof(fdt32_t); i++)
	{
		phandle = fdt32_to_cpu(list[i]);
		offset = fdt_node_offset_by_phandle(fdt, phandle);
		ofnode node;
		if(offset < 0){
			printf("sunxi pinctrl : Cannot find pinctrl node of %s \r\n",periph->name);
			return -EINVAL;
		}
		node = offset_to_ofnode(offset);
		pins_count = fdt_stringlist_count(fdt, offset, "pins");

		function = ofnode_read_string(node, "function");

		if(!function)
			return -EINVAL;

		if(-FDT_ERR_BADVALUE == pins_count){
			printf("sunxi pinctrl : bad value of %s's pins node \r\n",ofnode_get_name(node));
			return -EINVAL;
		}else if(-FDT_ERR_NOTFOUND == pins_count){
			printf("sunxi pinctrl : Cannot find pins prop of node %s \r\n",ofnode_get_name(node));
			return -EINVAL;
		}

		while(pins_count--)
		{
			pins_name = fdt_stringlist_get(fdt, offset, "pins", pins_count, &name_len);
			if(!pins_name){
				if(name_len == -FDT_ERR_NOTFOUND)
					printf("sunxi pinctrl : Cannot find pins prop of node %s \r\n",ofnode_get_name(node));
				return -EINVAL;
			}
			
			if(sunxi_get_pins_by_name(pins_name, &bank, &bank_pins) == -1 || 
					(bank > priv->bank_count -1) || (bank_pins > priv->pins_bank[bank].pins_bank_num))
			{
				printf("sunxi pinctrl : get pins %s error \r\n",pins_name);
				return -EINVAL;
			}
            
            curr_bank = priv->pins_bank + bank;
            curr_pinsdesc = curr_bank + bank_pins;
			curr_pinsdesc->n_pin = bank*32 + bank_pins;
			if(fdtdec_get_bool(fdt, offset, "bias-pull-up")){
				curr_pinsdesc->pull_cfg = SUNXI_GPIO_PULL_UP;
			}
			else if(fdtdec_get_bool(fdt, offset, "bias-pull-down"))
				curr_pinsdesc->pull_cfg = SUNXI_GPIO_PULL_DOWN;
			else if(fdtdec_get_bool(fdt, offset, "bias-disable"))
				curr_pinsdesc->pull_cfg = SUNXI_GPIO_PULL_DISABLE;

			multi_drv = fdt_getprop_u32_default_node(fdt, offset, 0,
						     "drive-strength", 0);
			if(multi_drv != ~0){
				if (multi_drv <= 10)
					multi_drv = SUNXI_PINCTRL_10_MA;
				else if (multi_drv <= 20)
					multi_drv = SUNXI_PINCTRL_20_MA;
				else if (multi_drv <= 30)
					multi_drv = SUNXI_PINCTRL_30_MA;
				else
					multi_drv = SUNXI_PINCTRL_40_MA;
			}

			curr_pinsdesc->multi_drv = multi_drv;
			ret = pinctrl_sunxi_pins_cfg(pins_name, function, *curr_pinsdesc);
			if(ret == -EINVAL)
				break;
			
		}
	}
    return 0;
}
#endif



const struct pinctrl_ops sunxi_pinctrl_ops = {
#ifdef CONFIG_SUNXI_PINCTRL_FULL
    .set_state = pinctrl_sunxi_set_state,
#else
    .set_state_simple = pinctrl_sunxi_set_state_simple,
#endif
};

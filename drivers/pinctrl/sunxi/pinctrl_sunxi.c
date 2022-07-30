#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include "pinctrl_sunxi.h"
#include <asm/gpio.h>

#ifdef CONFIG_SUNXI_PINCTRL_FULL
static int pinctrl_sunxi_set_state(struct udevice *dev, struct udevice *config)
{
    SUNXI_PINCTRL_DEBUG("set state dev->name is %s ,config->name is %s \r\n",
                dev->name, config->name);

    return 0;
}
#else

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

static int pinctrl_sunxi_set_state_simple(struct udevice *dev, struct udevice *periph)
{
	const fdt32_t *list;
	uint32_t phandle;
	int size, i, j, offset, pins_count, name_len;
	char *pins_name;
	const void *fdt = gd->fdt_blob;
	struct pinctrl_sunxi_priv *priv = dev_get_priv(dev);
	char *function;

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

		while(pins_count--){
			int bank;
			int pins_bank;
			int func_val;
			int pio;
			pins_name = fdt_stringlist_get(fdt, offset, "pins", pins_count, &name_len);
			if(!pins_name){
				if(name_len == -FDT_ERR_NOTFOUND)
					printf("sunxi pinctrl : Cannot find pins prop of node %s \r\n",ofnode_get_name(node));
				return -EINVAL;
			}
			
			if(sunxi_get_pins_by_name(pins_name, &bank, &pins_bank) == -1 || 
					(bank > priv->bank_count -1) || (pins_bank > priv->pins_bank[bank].pins_bank_num))
			{
				printf("sunxi pinctrl : get pins %s error \r\n",pins_name);
				return -EINVAL;
			}
			
			func_val =  pinctrl_sunxi_bank_funcVal(pins_name, function,priv->pins_bank[bank].pinctrl_bank_desc[pins_bank].pin_mux);
			if(func_val == -1)
			{
				printf("sunxi pinctrl : get func val for %s--%s error \r\n",pins_name,function);
				return -EINVAL;
			}
			pio = bank*32 + pins_bank;
			sunxi_gpio_set_cfgpin(pio, func_val);
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
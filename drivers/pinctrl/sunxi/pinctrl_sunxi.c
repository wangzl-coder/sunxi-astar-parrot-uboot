#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include "pinctrl_sunxi.h"


#ifdef CONFIG_SUNXI_PINCTRL_FULL
static int pinctrl_sunxi_set_state(struct udevice *dev, struct udevice *config)
{
    SUNXI_PINCTRL_DEBUG("set state dev->name is %s ,config->name is %s \r\n",
                dev->name, config->name);

    return 0;
}
#else

static int sunxi_pins_cfg(char *cfg_name, char *cfg_func, struct sunxi_pins_info pins_info)
{

	return 0;
}

static int pinctrl_sunxi_set_state_simple(struct udevice *dev, struct udevice *periph)
{
	const fdt32_t *list;
	uint32_t phandle;
	int size, i, j, offset, pins_count, name_len;
	char *pins_name;
	const void *fdt = gd->fdt_blob;
	struct pinctrl_sunxi_priv *priv = dev_get_priv(dev);

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

		if(-FDT_ERR_BADVALUE == pins_count){
			printf("sunxi pinctrl : bad value of %s's pins node \r\n",ofnode_get_name(node));
			return -EINVAL;
		}else if(-FDT_ERR_NOTFOUND == pins_count){
			printf("sunxi pinctrl : Cannot find pins prop of node %s \r\n",ofnode_get_name(node));
			return -EINVAL;
		}

		while(pins_count--){
			pins_name = fdt_stringlist_get(fdt, offset, "pins", pins_count, &name_len);
			if(!pins_name){
				if(name_len == -FDT_ERR_NOTFOUND)
					printf("sunxi pinctrl : Cannot find pins prop of node %s \r\n",ofnode_get_name(node));
				return -EINVAL;
			}

			SUNXI_PINCTRL_DEBUG("pins %d is %s for node %s \r\n",	\
				pins_count, fdt_stringlist_get(fdt, offset, "pins", pins_count, &name_len),	\
					ofnode_get_name(node));
			
				
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
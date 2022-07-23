



#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include "pinctrl_sunxi.h"


#ifdef CONFIG_SUNXI_PINCTRL_FULL
static int pinctrl_sunxi_set_state(struct udevice *dev, struct udevice *config)
{
    printf("sunxi pinctrl : set state dev->name is %s ,config->name is %s \r\n",
                dev->name, config->name);

    return 0;
}
#else
static int pinctrl_sunxi_set_state_simple(struct udevice *dev, struct udevice *periph)
{
    printf("sunxi pinctrl : set state simple dev->name is %s , periph->name is %s \r\n",
                dev->name, periph->name);
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
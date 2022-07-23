#include <dm.h>
#include <dm/pinctrl.h>
#include <common.h>
#include "pinctrl_sunxi.h"



static int pinctrl_sun8i_a33_probe(struct udevice *dev)
{
    printf("sunxi pinctrl : probe dev->name is %s",dev->name);

    return 0;
}



static const struct udevice_id sun8i_a33_pinctrl_ids[] = {
    {   .compatible = "allwinner,sun8i-a33-pinctrl" },
    {   }
};

U_BOOT_DRIVER(sun8i_a33_pinctrl) = {
    .name = "sun8i-a33-pinctrl",
    .id = UCLASS_PINCTRL,
    .of_match = sun8i_a33_pinctrl_ids,
    .priv_auto_alloc_size = sizeof(struct pinctrl_sunxi_priv),
    .probe = pinctrl_sun8i_a33_probe,
    .ops = &sunxi_pinctrl_ops,
};
#include <dm.h>
#include <dm/pinctrl.h>
#include <common.h>
#include "pinctrl_sunxi.h"


static const struct sunxi_pinctrl_desc sun8i_a33_pinctrl_desc[] = {
    
    SUNXI_PINS_CTRL(PD10,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_TX
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D10
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE) 	//must add for end flag
    ),
    SUNXI_PINS_CTRL(PD11,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_RX
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D11
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD12,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_RTS
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D12
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD13,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_CTS
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D13
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD14,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D14
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PD_PCM1),     //PCM1_SYNC (Cannot find in DT)
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD15,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D15
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PD_PCM1),     //PCM1_CLK (Cannot find in DT)
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF0,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D1
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG),     //JTAG_MS1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF1,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D0
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG),     //JTAG_DI1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
    
    SUNXI_PINS_CTRL(PF2,
        SUNXI_IO_MUX(uart0, SUN8I_A33_IOMUX_PF_UART0),  //UART0_TX
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),   //SDC0_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF3,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_CMD
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG),     //JTAG_DO1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF4,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D3
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG),     //UART0_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF5,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D2
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG),     //JTAG_CK1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
};

static struct sunxi_pins_info sun8i_a33_pins_info = {
    .pinctrl_desc = &sun8i_a33_pinctrl_desc,
    .pins_num = sizeof(sun8i_a33_pinctrl_desc)/sizeof(struct sunxi_pinctrl_desc)
};

static int pinctrl_sun8i_a33_probe(struct udevice *dev)
{
	struct pinctrl_sunxi_priv *priv = dev_get_priv(dev);
    SUNXI_PINCTRL_DEBUG("probe dev->name is %s \r\n",dev->name);
    priv->reg_base = dev_read_addr(dev);
	if(priv->reg_base == FDT_ADDR_T_NONE)
		return -EINVAL;
	
	SUNXI_PINCTRL_DEBUG("pio reg base is %x \r\n",priv->reg_base);
    return 0;
}


static const struct udevice_id sun8i_a33_pinctrl_ids[] = {
    {   .compatible = "allwinner,sun8i-a33-pinctrl" ,
        .data = (ulong) &sun8i_a33_pins_info
    },
    { /* sentinel */ }
};

U_BOOT_DRIVER(sun8i_a33_pinctrl) = {
    .name = "sun8i_a33_pinctrl",
    .id = UCLASS_PINCTRL,
    .of_match = sun8i_a33_pinctrl_ids,
    .priv_auto_alloc_size = sizeof(struct pinctrl_sunxi_priv),
    .probe = pinctrl_sun8i_a33_probe,
    .ops = &sunxi_pinctrl_ops,
};
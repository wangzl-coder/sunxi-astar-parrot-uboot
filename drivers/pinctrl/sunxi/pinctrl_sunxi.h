#ifndef PINCTRL_SUNXI_H
#define PINCTRL_SUNXI_H
#include <dm/pinctrl.h>


//#define ENABLE_SUNXI_PINCTRL_DEBUG

#ifdef 	ENABLE_SUNXI_PINCTRL_DEBUG
#define SUNXI_PINCTRL_DEBUG(fmt, arg...) printf("sunxi pinctrl : "fmt, ##arg);
#else
#define SUNXI_PINCTRL_DEBUG(fmt, arg...)
#endif


#define SUNXI_PINS_CTRL(name, ...)   {                                          \
        .pin_name = #name,                                                      \
            .pin_mux = (struct sunxi_pins_mux *) &((struct sunxi_pins_mux[]){   \
            __VA_ARGS__                                                         \
        })                                                                      \
        }

#define SUNXI_IO_MUX(func, val) {       \
            .pin_func = #func,          \
            .reg_val = val              \
        }

enum sunxi_iomux_reg_val{

    SUN8I_A33_IOMUX_PA_UART4 = 0x2,
    SUN8I_A33_IOMUX_PB_UART2 = 0x2,
    SUN8I_A33_IOMUX_PC_SDMMC2 = 0x3,
    SUN8I_A33_IOMUX_PD_UART1 = 0x3,
    SUN8I_A33_IOMUX_PD_UART3 = 0x3,
    SUN8I_A33_IOMUX_PD_SDMMC1 = 0x3,
    SUN8I_A33_IOMUX_PD_LCD = 0x2,
    SUN8I_A33_IOMUX_PD_PCM1 = 0x3,
    SUN8I_A33_IOMUX_PF_UART0 = 0x3,
    SUN8I_A33_IOMUX_PF_SDMMC0 = 0x2,
    SUN8I_A33_IOMUX_PF_JTAG = 0x2,
    SUN8I_A33_IOMUX_PG_UART1 = 0x2,
    SUN8I_A33_IOMUX_PG_SDMMC1 = 0x2,
    SUN8I_A33_IOMUX_PH_UART3 = 0x3,
    SUN8I_A33_IOMUX_DISABLE = 0x7,  //for end
    
};



struct sunxi_pins_mux{
    char *pin_func;
    enum sunxi_iomux_reg_val reg_val;
};

struct sunxi_pinctrl_desc{
    char *pin_name;
    struct sunxi_pins_mux *pin_mux;
};


extern const struct pinctrl_ops sunxi_pinctrl_ops;

struct pinctrl_sunxi_priv
{
    unsigned int reg_base;
};

struct sunxi_pins_info{
    const struct sunxi_pinctrl_desc *pinctrl_desc;
	unsigned int pins_num;
};

#endif
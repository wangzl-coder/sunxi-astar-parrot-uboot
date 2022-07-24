#ifndef PINCTRL_SUNXI_H
#define PINCTRL_SUNXI_H
#include <dm/pinctrl.h>



#define SUNXI_PINS_CTRL(name, ...)   {    \
            .pin_name = #name,            \
            .pin_mux = (struct sunxi_pins_mux *) &((struct sunxi_pins_mux[]){ \
                __VA_ARGS__ \
            })      \
        }

#define SUNXI_IO_MUX(func, val) { \
            .pin_func = #func, \
            .reg_val = val      \
        }

enum sunxi_iomux_reg_val{

    SUN8I_A33_IOMUX_START = 0x7,
    SUN8I_A33_IOMUX_PF_UART0 = 0x3,
    SUN8I_A33_IOMUX_PG_UART1 = 0x2,
    SUN8I_A33_IOMUX_PB_UART2 = 0x2,
    SUN8I_A33_IOMUX_PD_UART3 = 0x3,
    SUN8I_A33_IOMUX_PH_UART3 = 0x3,
    SUN8I_A33_IOMUX_PA_UART4 = 0x2,
    SUN8I_A33_IOMUX_PF_SDMMC0 = 0x2,
    SUN8I_A33_IOMUX_PD_SDMMC1 = 0x3,
    SUN8I_A33_IOMUX_PG_SDMMC1 = 0x2,
    SUN8I_A33_IOMUX_PC_SDMMC2 = 0x3,
    SUN8I_A33_IOMUX_END = 0x7,
    
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
    unsigned int test;
};


#endif
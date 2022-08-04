#ifndef PINCTRL_SUNXI_H
#define PINCTRL_SUNXI_H
#include <dm/pinctrl.h>
#include <asm/arch/gpio.h>

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

#define SUNXI_PINS_BANK_DESC(arry_desc)    \
{       \
    .pinctrl_bank_desc =(struct sunxi_pinctrl_desc *) &arry_desc,   \
    .pins_bank_num = sizeof(arry_desc)/sizeof(struct sunxi_pinctrl_desc)     \
}

#define ID(_compat_, _soc_data_) \
	{ .compatible = _compat_, .data = (ulong)&soc_data_##_soc_data_ }


#define SUNXI_GPIOS_PER_BANK	SUNXI_GPIO_A_NR

enum sunxi_iomux_reg_val{

	SUN8I_A33_IOMUX_PA_SPI1 = 0x2,
	SUN8I_A33_IOMUX_PA_JTAG0 = 0x3,
    SUN8I_A33_IOMUX_PA_UART4 = 0x2,
    SUN8I_A33_IOMUX_PB_UART2 = 0x2,
	SUN8I_A33_IOMUX_PB_PCM0 = 0x2,
	SUN8I_A33_IOMUX_PC_NAND = 0x2,
    SUN8I_A33_IOMUX_PC_SDMMC2 = 0x3,
    SUN8I_A33_IOMUX_PD_UART1 = 0x3,
    SUN8I_A33_IOMUX_PD_UART3 = 0x3,
    SUN8I_A33_IOMUX_PD_SDMMC1 = 0x3,
    SUN8I_A33_IOMUX_PD_LCD = 0x2,
	SUN8I_A33_IOMUX_PD_LVDS = 0x3,
    SUN8I_A33_IOMUX_PD_PCM1 = 0x3,
    SUN8I_A33_IOMUX_PE_CSI = 0x2,
    SUN8I_A33_IOMUX_PE_TWI2 = 0x2,
    SUN8I_A33_IOMUX_PF_UART0 = 0x3,
    SUN8I_A33_IOMUX_PF_SDMMC0 = 0x2,
    SUN8I_A33_IOMUX_PF_JTAG1 = 0x2,
    SUN8I_A33_IOMUX_PG_UART1 = 0x2,
    SUN8I_A33_IOMUX_PG_SDMMC1 = 0x2,
    SUN8I_A33_IOMUX_PG_PCM1 = 0x2,
	SUN8I_A33_IOMUX_PH_PWM0 = 0x2,
	SUN8I_A33_IOMUX_PH_PWM1 = 0x2,
	SUN8I_A33_IOMUX_PH_TWI0 = 0x2,
	SUN8I_A33_IOMUX_PH_TWI1 = 0x2,
	SUN8I_A33_IOMUX_PH_SPI0 = 0x2,
    SUN8I_A33_IOMUX_PH_UART3 = 0x3,
    SUN8I_A33_IOMUX_DISABLE = 0x7,  //for end
    
};

extern int gpio_sunxi_bind(struct udevice *parent);

static const struct sunxi_gpio_soc_data soc_data_a_all = {
	.start = 0,
	.no_banks = SUNXI_GPIO_BANKS,
};

static const struct sunxi_gpio_soc_data soc_data_l_1 = {
	.start = 'L' - 'A',
	.no_banks = 1,
};

static const struct sunxi_gpio_soc_data soc_data_l_2 = {
	.start = 'L' - 'A',
	.no_banks = 2,
};

static const struct sunxi_gpio_soc_data soc_data_l_3 = {
	.start = 'L' - 'A',
	.no_banks = 3,
};
/*
static const struct udevice_id sunxi_pinctrl_ids[] = {
	ID("allwinner,sun4i-a10-pinctrl",	a_all),
	ID("allwinner,sun5i-a10s-pinctrl",	a_all),
	ID("allwinner,sun5i-a13-pinctrl",	a_all),
	ID("allwinner,sun50i-h5-pinctrl",	a_all),
	ID("allwinner,sun6i-a31-pinctrl",	a_all),
	ID("allwinner,sun6i-a31s-pinctrl",	a_all),
	ID("allwinner,sun7i-a20-pinctrl",	a_all),
	ID("allwinner,sun8i-a23-pinctrl",	a_all),
	ID("allwinner,sun8i-a33-pinctrl",	a_all),
	ID("allwinner,sun8i-a83t-pinctrl",	a_all),
	ID("allwinner,sun8i-h3-pinctrl",	a_all),
	ID("allwinner,sun8i-r40-pinctrl",	a_all),
	ID("allwinner,sun8i-v3s-pinctrl",	a_all),
	ID("allwinner,sun9i-a80-pinctrl",	a_all),
	ID("allwinner,sun50i-a64-pinctrl",	a_all),
	ID("allwinner,sun6i-a31-r-pinctrl",	l_2),
	ID("allwinner,sun8i-a23-r-pinctrl",	l_1),
	ID("allwinner,sun8i-a83t-r-pinctrl",	l_1),
	ID("allwinner,sun8i-h3-r-pinctrl",	l_1),
	ID("allwinner,sun9i-a80-r-pinctrl",	l_3),
	ID("allwinner,sun50i-a64-r-pinctrl",	l_1),
	{ }
};*/

extern const struct driver gpio_sunxi;

struct sunxi_pins_mux{
    char *pin_func;
    enum sunxi_iomux_reg_val reg_val;
};

struct sunxi_pinctrl_desc{
    char *pin_name;
    u32 n_pin;
    u32 pull_cfg;
    u32 multi_drv;
    struct sunxi_pins_mux *pin_mux;
};


extern const struct pinctrl_ops sunxi_pinctrl_ops;

struct sunxi_pins_bank{
    struct sunxi_pinctrl_desc *pinctrl_bank_desc;
	unsigned int pins_bank_num;
};

struct pinctrl_sunxi_priv
{
    unsigned int reg_base;
    const struct sunxi_pins_bank *pins_bank;
    unsigned int bank_count;
};

#endif
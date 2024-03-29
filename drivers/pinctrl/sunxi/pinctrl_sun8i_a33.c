#include <dm.h>
#include <dm/pinctrl.h>
#include <common.h>
#include "pinctrl_sunxi.h"



const struct sunxi_pinctrl_desc sun8i_a33_portA_desc[] = {
    
	SUNXI_PINS_CTRL(PA0,
        SUNXI_IO_MUX(spi1, SUN8I_A33_IOMUX_PA_SPI1),  //SPI1_CS
		SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PA_JTAG0),  //JTAG_MS0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE) 	//must add for end flag
    ),
	SUNXI_PINS_CTRL(PA1,
		SUNXI_IO_MUX(spi1, SUN8I_A33_IOMUX_PA_SPI1), 	//SPI1_CLK
		SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PA_JTAG0),	//JTAG_CK0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PA2,
		SUNXI_IO_MUX(spi1, SUN8I_A33_IOMUX_PA_SPI1), 	//SPI1_MOSI
		SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PA_JTAG0),	//JTAG_DO0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PA3,
		SUNXI_IO_MUX(spi1, SUN8I_A33_IOMUX_PA_SPI1), 	//SPI1_MISO
		SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PA_JTAG0),	//JTAG_DI0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PA4,
		SUNXI_IO_MUX(uart4, SUN8I_A33_IOMUX_PA_UART4), 	//UART4_TX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PA5,
		SUNXI_IO_MUX(uart4, SUN8I_A33_IOMUX_PA_UART4), 	//UART4_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PA6,
		SUNXI_IO_MUX(uart4, SUN8I_A33_IOMUX_PA_UART4), 	//UART4_RTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PA7,
		SUNXI_IO_MUX(uart4, SUN8I_A33_IOMUX_PA_UART4), 	//UART4_CTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
};

const struct sunxi_pinctrl_desc sun8i_a33_portB_desc[] = {
	SUNXI_PINS_CTRL(PB0,
		SUNXI_IO_MUX(uart2, SUN8I_A33_IOMUX_PB_UART2), 	//UART2_TX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PB1,
		SUNXI_IO_MUX(uart2, SUN8I_A33_IOMUX_PB_UART2), 	//UART2_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PB2,
		SUNXI_IO_MUX(uart2, SUN8I_A33_IOMUX_PB_UART2), 	//UART2_RTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PB3,
		SUNXI_IO_MUX(uart2, SUN8I_A33_IOMUX_PB_UART2), 	//UART2_CTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PB4,
		SUNXI_IO_MUX(pcm0, SUN8I_A33_IOMUX_PB_PCM0), 	//PCM0_SYNC
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PB5,
		SUNXI_IO_MUX(pcm0, SUN8I_A33_IOMUX_PB_PCM0), 	//PCM0_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PB6,
		SUNXI_IO_MUX(pcm0, SUN8I_A33_IOMUX_PB_PCM0), 	//PCM0_DOUT
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PB7,
		SUNXI_IO_MUX(pcm0, SUN8I_A33_IOMUX_PB_PCM0), 	//PCM0_DIN
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
};


const struct sunxi_pinctrl_desc sun8i_a33_portC_desc[] = {
	SUNXI_PINS_CTRL(PC0,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_WE
		SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PC_NAND), 	//SPI0_MOSI
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC1,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_ALE
		SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PC_NAND), 	//SPI0_MISO
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC2,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_CLE
		SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PC_NAND), 	//SPI0_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC3,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_CE1
		SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PC_NAND), 	//SPI0_CS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC4,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_CE0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC5,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_RE
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC6,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_RB0
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_CMD
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC7,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_RB1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC8,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ0
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC9,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ1
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC10,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ2
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D2
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC11,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ3
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D3
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC12,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ4
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D4
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC13,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ5
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D5
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC14,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ6
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D6
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC15,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQ7
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_D7
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC16,
		SUNXI_IO_MUX(nand0, SUN8I_A33_IOMUX_PC_NAND), 	//NAND_DQS
		SUNXI_IO_MUX(mmc2, SUN8I_A33_IOMUX_PC_SDMMC2), 	//SDC2_RST
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC17,
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PC18,
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
};

const struct sunxi_pinctrl_desc sun8i_a33_portD_desc[] = {
	SUNXI_PINS_CTRL(PD0,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD1,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD2,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D2
		SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PD_SDMMC1),	//SDC1_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD3,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D3
		SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PD_SDMMC1),	//SDC1_CMD
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD4,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D4
		SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PD_SDMMC1),	//SDC1_D0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD5,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D5
		SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PD_SDMMC1),	//SDC1_D1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD6,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D6
		SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PD_SDMMC1),	//SDC1_D2
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD7,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D7
		SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PD_SDMMC1),	//SDC1_D3
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD8,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D8
		SUNXI_IO_MUX(uart3, SUN8I_A33_IOMUX_PD_UART3),	//UART3_TX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
	SUNXI_PINS_CTRL(PD9,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),	//LCD_D9
		SUNXI_IO_MUX(uart3, SUN8I_A33_IOMUX_PD_UART3),	//UART3_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
    SUNXI_PINS_CTRL(PD10,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_TX
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D10
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD11,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D11
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD12,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D12
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_RTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD13,
		SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D13
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PD_UART1),  //UART1_CTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD14,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D14
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PD_PCM1),     //PCM1_SYNC
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PD15,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D15
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PD_PCM1),     //PCM1_CLK 
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD16,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D16
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PD_PCM1),     //PCM1_DOUT
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD17,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D17
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PD_PCM1),     //PCM1_DIN
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD18,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D18
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VP0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD19,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D19
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VN0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD20,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D20
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VP1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD21,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D21
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VN1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD22,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D22
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VP2
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD23,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_D23
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VN2
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD24,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_CLK
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VPC
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD25,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_DE
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VNC
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD26,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_HSYNC
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VP3
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PD27,
        SUNXI_IO_MUX(lcd0, SUN8I_A33_IOMUX_PD_LCD),     //LCD_VSYNC
        SUNXI_IO_MUX(lvds, SUN8I_A33_IOMUX_PD_LVDS),     //LVDS_VN3
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
};

const struct sunxi_pinctrl_desc sun8i_a33_portE_desc[] = {
	SUNXI_PINS_CTRL(PE0,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_PCLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE1,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_MCLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE2,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_HSYNC
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE3,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_VSYNC
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE4,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE5,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE6,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D2
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE7,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D3
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE8,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D4
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE9,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D5
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE10,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D6
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE11,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_D7
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE12,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_SCK
        SUNXI_IO_MUX(twi2, SUN8I_A33_IOMUX_PE_TWI2),  //TWI2_SCK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PE13,
        SUNXI_IO_MUX(csi, SUN8I_A33_IOMUX_PE_CSI),  //CSI_SDA
        SUNXI_IO_MUX(twi2, SUN8I_A33_IOMUX_PE_TWI2),  //TWI2_SDA
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
};

const struct sunxi_pinctrl_desc sun8i_a33_portF_desc[] = {
    SUNXI_PINS_CTRL(PF0,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D1
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG1),     //JTAG_MS1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF1,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D0
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG1),     //JTAG_DI1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
	),
    
    SUNXI_PINS_CTRL(PF2,
        SUNXI_IO_MUX(uart0, SUN8I_A33_IOMUX_PF_UART0),  //UART0_TX
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),   //SDC0_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF3,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_CMD
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG1),     //JTAG_DO1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF4,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D3
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG1),     //UART0_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
    SUNXI_PINS_CTRL(PF5,
        SUNXI_IO_MUX(mmc0, SUN8I_A33_IOMUX_PF_SDMMC0),  //SDC0_D2
        SUNXI_IO_MUX(jtag, SUN8I_A33_IOMUX_PF_JTAG1),     //JTAG_CK1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
};

const struct sunxi_pinctrl_desc sun8i_a33_portG_desc[] = {
	SUNXI_PINS_CTRL(PG0,
        SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PG_SDMMC1),  //SDC1_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG1,
        SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PG_SDMMC1),  //SDC1_CMD
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG2,
        SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PG_SDMMC1),  //SDC1_D0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG3,
        SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PG_SDMMC1),  //SDC1_D1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG4,
        SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PG_SDMMC1),  //SDC1_D2
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG5,
        SUNXI_IO_MUX(mmc1, SUN8I_A33_IOMUX_PG_SDMMC1),  //SDC1_D3
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG6,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PG_UART1),  //UART1_TX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG7,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PG_UART1),  //UART1_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG8,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PG_UART1),  //UART1_RTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG9,
        SUNXI_IO_MUX(uart1, SUN8I_A33_IOMUX_PG_UART1),  //UART1_CTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG10,
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PG_PCM1),  //PCM1_SYNC
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG11,
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PG_PCM1),  //PCM1_CLK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG12,
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PG_PCM1),  //PCM1_DOUT
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PG13,
        SUNXI_IO_MUX(pcm1, SUN8I_A33_IOMUX_PG_PCM1),  //PCM1_DIN
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
};

const struct sunxi_pinctrl_desc sun8i_a33_portH_desc[] = {
	SUNXI_PINS_CTRL(PH0,
        SUNXI_IO_MUX(pwm0, SUN8I_A33_IOMUX_PH_PWM0),  //PWM0
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH1,
        SUNXI_IO_MUX(pwm1, SUN8I_A33_IOMUX_PH_PWM1),  //PWM1
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH2,
        SUNXI_IO_MUX(twi0, SUN8I_A33_IOMUX_PH_TWI0),  //TWI0_SCK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH3,
        SUNXI_IO_MUX(twi0, SUN8I_A33_IOMUX_PH_TWI0),  //TWI0_SDA
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH4,
        SUNXI_IO_MUX(twi1, SUN8I_A33_IOMUX_PH_TWI1),  //TWI1_SCK
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH5,
        SUNXI_IO_MUX(twi1, SUN8I_A33_IOMUX_PH_TWI1),  //TWI1_SDA
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH6,
        SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PH_SPI0),  //SPI0_CS
        SUNXI_IO_MUX(uart3, SUN8I_A33_IOMUX_PH_UART3),  //UART3_TX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH7,
        SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PH_SPI0),  //SPI0_CLK
        SUNXI_IO_MUX(uart3, SUN8I_A33_IOMUX_PH_UART3),  //UART3_RX
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH8,
        SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PH_SPI0),  //SPI0_DOUT
        SUNXI_IO_MUX(uart3, SUN8I_A33_IOMUX_PH_UART3),  //UART3_RTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
	SUNXI_PINS_CTRL(PH9,
        SUNXI_IO_MUX(spi0, SUN8I_A33_IOMUX_PH_SPI0),  //SPI0_DIN
        SUNXI_IO_MUX(uart3, SUN8I_A33_IOMUX_PH_UART3),  //UART3_CTS
		SUNXI_IO_MUX(disable, SUN8I_A33_IOMUX_DISABLE)
    ),
};

static const struct sunxi_pins_bank sun8i_a33_pins_bank[] = 
{
	SUNXI_PINS_BANK_DESC(sun8i_a33_portA_desc),
	SUNXI_PINS_BANK_DESC(sun8i_a33_portB_desc),
	SUNXI_PINS_BANK_DESC(sun8i_a33_portC_desc),
	SUNXI_PINS_BANK_DESC(sun8i_a33_portD_desc),
	SUNXI_PINS_BANK_DESC(sun8i_a33_portE_desc),
	SUNXI_PINS_BANK_DESC(sun8i_a33_portF_desc),
	SUNXI_PINS_BANK_DESC(sun8i_a33_portG_desc),
	SUNXI_PINS_BANK_DESC(sun8i_a33_portH_desc),
};

static int pinctrl_sun8i_a33_probe(struct udevice *dev)
{
	struct pinctrl_sunxi_priv *priv = dev_get_priv(dev);
    SUNXI_PINCTRL_DEBUG("probe dev->name is %s \r\n",dev->name);
    priv->reg_base = dev_read_addr(dev);
	priv->pins_bank = (const struct sunxi_pins_bank*) &sun8i_a33_pins_bank;
	priv->bank_count = sizeof(sun8i_a33_pins_bank)/sizeof(struct sunxi_pins_bank);
	if(priv->reg_base == FDT_ADDR_T_NONE)
		return -EINVAL;
	
	SUNXI_PINCTRL_DEBUG("pio bank_count is %x \r\n",priv->bank_count);
    return 0;
}

static const struct udevice_id sun8i_a33_pinctrl_ids[] = {
	ID("allwinner,sun8i-a33-pinctrl",	a_all),
	ID("allwinner,sun8i-a23-r-pinctrl",	l_1),
	{ }
};

U_BOOT_DRIVER(sun8i_a33_pinctrl) = {
    .name = "sun8i_a33_pinctrl",
    .id = UCLASS_PINCTRL,
    .of_match = sun8i_a33_pinctrl_ids,
    .priv_auto_alloc_size = sizeof(struct pinctrl_sunxi_priv),
	.bind = gpio_sunxi_bind,
    .probe = pinctrl_sun8i_a33_probe,
    .ops = &sunxi_pinctrl_ops,
};
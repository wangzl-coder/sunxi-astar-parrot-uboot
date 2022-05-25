/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2014 Chen-Yu Tsai <wens@csie.org>
 *
 * Configuration settings for the Allwinner A23 (sun8i) CPU
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * A33 specific configuration
 */

/*
 * Include common sunxi configuration where most the settings are
 */
#include <configs/sunxi-common.h>

#define CONFIG_MACH_SUN8IW5P1_A33

#define UBOOT_VERSION "1.1.0"

#define UBOOT_PLATFORM "1.0.0"




#endif /* __CONFIG_H */

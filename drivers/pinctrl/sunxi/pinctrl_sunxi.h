#ifndef PINCTRL_SUNXI_H
#define PINCTRL_SUNXI_H
#include <dm/pinctrl.h>


extern const struct pinctrl_ops sunxi_pinctrl_ops;

struct pinctrl_sunxi_priv
{
    unsigned int test;
};


#endif
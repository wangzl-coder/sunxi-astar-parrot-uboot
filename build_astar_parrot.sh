#!/bin/bash

make distclean
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- sun8iw5p1_a33_astar_parrot_defconfig
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- clean
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- 

#!/bin/bash

make arch=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean
make arch=arm CROSS_COMPILE=arm-linux-gnueabihf- clean
make arch=arm CROSS_COMPILE=arm-linux-gnueabihf- A33-astar-parrot_defconfig
make arch=arm CROSS_COMPILE=arm-linux-gnueabihf-

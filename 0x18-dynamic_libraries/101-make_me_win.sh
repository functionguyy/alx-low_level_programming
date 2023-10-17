#!/bin/bash
wget -P /tmp/ https://raw.github.com/functionguyy/alx-low_level_programming/master/0x18-dynamic_libraries/libinject.so
export LD_PRELOAD=/tmp/libinject.so

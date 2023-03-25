#!/bin/bash
wget -qP /tmp/ https://github.com/functionguyy/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libinject.so
export LD_PRELOAD=/tmp/libinject.so

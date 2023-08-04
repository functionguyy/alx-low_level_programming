#!/bin/bash

# create object files .c files in current directory
gcc -c -Wall -Werror -Wextra *.c
# create static library named liball from .o files in current directory
ar -rc liball.a *.o
# index the liball.a static library
ranlib liball.a

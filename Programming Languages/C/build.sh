#!/bin/sh

set -xe

# Assuming gcc is the C compiler
gcc -Wall -Wextra -ggdb -o main main.c -lm
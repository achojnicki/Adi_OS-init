#!/bin/bash

export LDFLAGS="-static"

gcc -c main.c $(python3-config --includes) -static
gcc -o adios-init main.o $(python3-config --ldflags) -static
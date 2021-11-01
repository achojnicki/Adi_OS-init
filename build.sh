#!/bin/bash

#export LDFLAGS="-static"

#gcc -c main.c $(python3-config --includes) -static -static-libgcc -static-libstdc++

#gcc -o adios-init main.o $(python3-config --ldflags) -static -static-libgcc -static-libstdc++
#gcc -o adios-init main.o -static -static-libgcc -static-libstdc++
gcc -static main.c -o adios-init $(pkg-config --libs --cflags python3) -lm -lutil -ldl -lz -lexpat -lpthread -lc
#gcc -static ./main.c -o adios-init
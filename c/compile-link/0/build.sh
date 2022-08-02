#!/bin/bash

rm -rf *.o main
# gcc main.c stack.c -o main

gcc -c main.c
gcc -c stack.c

## multiple definition of `push'; main.o:main.c:(.text+0x0): first defined here
gcc main.o stack.o -o main



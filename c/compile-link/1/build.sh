#!/bin/bash

# gcc main.c stack.c -o main

gcc -c main.c
gcc -c stack.c
gcc main.o stack.o -o main



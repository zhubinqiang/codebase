#!/bin/bash -ex

rm -rf *.o lib*.a main main2

gcc -c stack/stack.c stack/push.c stack/pop.c stack/is_empty.c
ar rs libstack.a stack.o push.o pop.o is_empty.o

## ranlib: generate an index to an archive
# ar r libstack.a stack.o push.o pop.o is_empty.o
# ranlib libstack.a

gcc main.c -L. -lstack -Istack -o main
objdump -d main

# gcc main.c push.o pop.o is_empty.o stack.o -Istack -o main2
# objdump -d main2



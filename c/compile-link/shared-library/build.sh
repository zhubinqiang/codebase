#!/bin/bash -ex

rm -rf *.o lib*.so* main main2

## pic: position independent code
gcc -c -g -fPIC stack/stack.c stack/push.c stack/pop.c stack/is_empty.c

# gcc -shared -o libstack.so stack.o push.o pop.o is_empty.o
gcc -shared -Wl,-soname,libstack.so.1 -o libstack.so.1.0 stack.o push.o pop.o is_empty.o
ln -sf libstack.so.1.0 libstack.so


gcc main.c -L. -lstack -Istack -o main

gcc main.c -L. -lstack -Istack -o main2 -Wl,-rpath,${PWD}
# objdump -dS main

## add path to /etc/ld.so.conf
## sudo ldconfig

# LD_LIBRARY_PATH=. ./main




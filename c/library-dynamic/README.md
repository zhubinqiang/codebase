
## share library
PIC: position independent code

```sh
gcc a.c b.c c.c -I. -fPIC -shared -o libtest.so
```


```sh
gcc a.c b.c c.c -I .-fPIC -shared -Wl,-soname,libtest.so.2 -o libtest.so.2.1

ln -sf libtest.so.2.1 libtest.so.2
ln -sf libtest.so.2 libtest.so
```

```sh
$ readelf -d libtest.so | grep soname
0x000000000000000e (SONAME)             Library soname: [libtest.so.2]
```



```sh
gcc dynamic.c -I . -L . -ltest -o dynamic
```

> `-I` 告诉编译器去哪里找头文件
> `-L` 去哪里找库文件, **即使库文件在当前目录，编译器也不会主动去找的**。
> `-ltest` 告诉编译器要使用 libtest.so 或者 libtest.a
> 不知道为啥 源文件要写在 `-ltest` 的前面否则会报undefined reference

也可以通过环境变量指定
```sh
export C_INCLUDE_PATH=/path/to/include:${C_INCLUDE_PATH}
export CPP_INCLUDE_PATH=/path/to/include:${CPP_INCLUDE_PATH}
```

## 运行带有动态库的可执行文件
执行的时候要导入到 `LD_LIBRARY_PATH` 变量中。否则不一定能找到，会报"cannot open shared object file"  
```sh
export LD_LIBRARY_PATH=.
./dynamic
```

上面的是临时执行，永久生效可以把路径写入`/etc/ld.so.conf` 或 `/etc/ld.so.conf.d/xxx.conf` 
再或者把动态库拷贝到默认找寻的动态库目录像`/usr/lib64`
再后执行 `ldconfig`

也可以使用 `patchelf` 命令指定
```sh
patchelf --set-rpath $PWD ./dynamic
```


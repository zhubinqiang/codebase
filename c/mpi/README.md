
编译和执行MPI程序通常需要以下步骤：

1. 编写MPI程序：在一个或多个源代码文件中编写MPI程序，包括MPI函数的调用和相应的逻辑代码。

2. 设置MPI环境：在执行MPI程序之前，需要先设置MPI环境。这可以通过在终端中加载MPI库来完成。通常，使用 `mpicc` 命令来编译MPI程序。

    ```sh
    $ # source /path/to/file/setenv.sh
    $ mpicc -o sum_example sum_example.c
    ```

   上述命令将源文件 `sum_example.c` 编译为可执行文件 `sum_example`。编译过程中会自动链接MPI库。

3. 运行MPI程序：使用 `mpiexec` 命令来运行MPI程序。通常，指定要运行的进程数量和可执行文件的路径。

   ```sh
   $ mpiexec -n <num_processes> ./sum_example
   ```

   在上述命令中，`<num_processes>` 是要启动的进程数量。可以根据需要设置合适的值。

   运行MPI程序后，每个进程将执行相应的代码，并通过MPI函数进行通信和计算。

需要注意的是，MPI程序需要在支持MPI的环境中执行。根据您所使用的MPI实现和操作系统，可能需要进行额外的设置和配置。


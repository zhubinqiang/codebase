#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 10

int main(int argc, char** argv) {
    int rank, size;
    int local_sum = 0, global_sum = 0;
    int array[ARRAY_SIZE];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 每个进程生成随机数组
    srand(rank);
    printf("rank = %d\n", rank);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10;
        printf("%d\t", array[i]);
    }
    printf("\n");

    // 每个进程计算局部和
    for (int i = rank; i < ARRAY_SIZE; i += size) {
        local_sum += array[i];
    }

    // 将局部和求和得到全局和
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // 进程0输出结果
    if (rank == 0) {
        printf("Total sum: %d\n", global_sum);
    }

    MPI_Finalize();
    return 0;
}


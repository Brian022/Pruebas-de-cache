#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

int main(void)
{
    static int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE] = {0};
    int i, j, k;

    srand(time(NULL));

    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // Get the start time

    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            for(k = 0; k < SIZE; k++)
                C[i][j] += A[i][k] * B[k][j];

    clock_gettime(CLOCK_MONOTONIC, &end); // Get the end time

    // Calculate the elapsed time in nanoseconds
    unsigned long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);

    printf("Matriz de tamano = %d\t \n Tiempo de: %llu nanosegundos\n", SIZE, elapsed_ns);

    return 0;
}
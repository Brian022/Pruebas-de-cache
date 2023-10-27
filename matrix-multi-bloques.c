#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000


void matrix_multiply(int A[][N], int B[][N], int C[][N], int blockSize) {
    int i, j, k, x, y, z;

    for (i = 0; i < N; i += blockSize) {
        for (j = 0; j < N; j += blockSize) {
            for (k = 0; k < N; k += blockSize) {
                for (x = i; x < i + blockSize; x++) {
                    for (y = j; y < j + blockSize; y++) {
                        for (z = k; z < k + blockSize; z++) {
                            C[x][y] += A[x][z] * B[z][y];
                        }
                    }
                }
            }
        }
    }
}

int main() {

    static int A[N][N], B[N][N], C[N][N]= {0};

    srand(time(NULL));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {   
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }
    }
    int blockSize = 20;  
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // Get the start time

    matrix_multiply(A, B, C, blockSize);

    clock_gettime(CLOCK_MONOTONIC, &end); // Get the end time

    // Calculate the elapsed time in nanoseconds
    unsigned long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);

    printf("Matriz de tamano = %d\t \n Tiempo de: %llu nanosegundos\n", N, elapsed_ns);
    // Imprime la matriz resultante 
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}
// matrix multiplication using Strassen's algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 64
#define RUNS 10
void normalMultiply(int A[N][N], int B[N][N], int C[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    int i, j;
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = n / 2;
    int A11[newSize][newSize];
    int A12[newSize][newSize];
    int A21[newSize][newSize];
    int A22[newSize][newSize];
    int B11[newSize][newSize];
    int B12[newSize][newSize];
    int B21[newSize][newSize];
    int B22[newSize][newSize];
    int M1[newSize][newSize];
    int M2[newSize][newSize];
    int M3[newSize][newSize];
    int M4[newSize][newSize];
    int M5[newSize][newSize];
    int M6[newSize][newSize];
    int M7[newSize][newSize];
    int T1[newSize][newSize];
    int T2[newSize][newSize];
    for (i = 0; i < newSize; i++)
    {
        for (j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    addMatrix(newSize, A11, A22, T1);
    addMatrix(newSize, B11, B22, T2);
    strassen(newSize, T1, T2, M1);
    addMatrix(newSize, A21, A22, T1);
    strassen(newSize, T1, B11, M2);
    subtractMatrix(newSize, B12, B22, T2);
    strassen(newSize, A11, T2, M3);
    subtractMatrix(newSize, B21, B11, T2);
    strassen(newSize, A22, T2, M4);
    addMatrix(newSize, A11, A12, T1);
    strassen(newSize, T1, B22, M5);
    subtractMatrix(newSize, A21, A11, T1);
    addMatrix(newSize, B11, B12, T2);
    strassen(newSize, T1, T2, M6);
    subtractMatrix(newSize, A12, A22, T1);
    addMatrix(newSize, B21, B22, T2);
    strassen(newSize, T1, T2, M7);
    for (i = 0; i < newSize; i++)
    {
        for (j = 0; j < newSize; j++)
        {
            C[i][j] =
                M1[i][j]
                + M4[i][j]
                - M5[i][j]
                + M7[i][j];
        }
    }
    for (i = 0; i < newSize; i++)
    {
        for (j = 0; j < newSize; j++)
        {
            C[i][j + newSize] =
                M3[i][j] + M5[i][j];
        }
    }
    for (i = 0; i < newSize; i++)
    {
        for (j = 0; j < newSize; j++)
        {
            C[i + newSize][j] =
                M2[i][j] + M4[i][j];
        }
    }
    for (i = 0; i < newSize; i++)
    {
        for (j = 0; j < newSize; j++)
        {
            C[i + newSize][j + newSize] =
                M1[i][j]
                - M2[i][j]
                + M3[i][j]
                + M6[i][j];
        }
    }
}
int compareMatrices(int A[N][N], int B[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (A[i][j] != B[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
void printMatrix(int A[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%5d ", A[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    static int A[N][N];
    static int B[N][N];
    static int C_normal[N][N];
    static int C_strassen[N][N];
    int i, j, r;
    clock_t start, end;
    double normalTime;
    double strassenTime;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = (i + j) % 10 + 1;
            B[i][j] = (i * j) % 10 + 1;
        }
    }
    start = clock();
    for (r = 0; r < RUNS; r++)
    {
        normalMultiply(A, B, C_normal);
    }
    end = clock();
    normalTime =
        ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    start = clock();
    for (r = 0; r < RUNS; r++)
    {
        strassen(N, A, B, C_strassen);
    }
    end = clock();
    strassenTime =
        ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("\n");
    printf("============================================\n");
    printf("       64 x 64 MATRIX MULTIPLICATION\n");
    printf("============================================\n");
    printf("\nMatrix Size: %d x %d\n", N, N);
    printf("Total Elements: %d\n", N * N);
    printf("\n--------------------------------------------\n");
    printf("NORMAL MATRIX MULTIPLICATION\n");
    printf("--------------------------------------------\n");
    printf("Total Time for %d runs : %.3f ms\n",
           RUNS, normalTime);
    printf("Average Time           : %.6f ms\n",
           normalTime / RUNS);
    printf("Complexity             : O(n^3)\n");
    printf("\n--------------------------------------------\n");
    printf("STRASSEN MATRIX MULTIPLICATION\n");
    printf("--------------------------------------------\n");
    printf("Total Time for %d runs : %.3f ms\n",
           RUNS, strassenTime);
    printf("Average Time           : %.6f ms\n",
           strassenTime / RUNS);
    printf("Complexity             : O(n^2.807)\n");
    printf("\n--------------------------------------------\n");
    printf("COMPARISON\n");
    printf("--------------------------------------------\n");
    printf("Normal operations      : %d\n",
           N * N * N);
    printf("Time Difference        : %.3f ms\n",
           normalTime - strassenTime);
    if (compareMatrices(C_normal, C_strassen))
    {
        printf("Result Check           : CORRECT\n");
    }
    else
    {
        printf("Result Check           : INCORRECT\n");
    }
    printf("\n============================================\n");
    return 0;
}
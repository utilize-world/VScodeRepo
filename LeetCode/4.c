#include <stdio.h>

void rotate(int matrix[][3], int matrixSize, int *matrixColSize) // 原地旋转矩阵

{
    int i, j;
    int scale = matrixColSize[0];
    int endCount = scale;
    int temp = 0;
    for (i = 0; i < scale; i++) // 矩阵转置 这里一定要注意i，j的边界条件
    {
        for (j = i; j < scale; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    printMatrix(matrix, 3);
    for (i = 0; i < scale / 2; i++) // 沿着中心翻折矩阵
    {
        for (j = 0; j < scale; j++)
        {
            temp = matrix[j][i];
            matrix[j][i] = matrix[j][endCount - 1];
            matrix[j][endCount - 1] = temp;
        }
        endCount--;
    }
}

void printMatrix(int matrix[][3], int scale)
{
    for (int i = 0; i < scale; i++)
    {
        for (int j = 0; j < scale; j++)
        {

            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(matrix, 3);
    int colscale[3] = {3, 3, 3};
    rotate(matrix, 9, colscale);
    printMatrix(matrix, 3);
}
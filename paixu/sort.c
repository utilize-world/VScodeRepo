#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define arrayLEN 10
void InsertSort(int A[]) // 插入排序
{
    int i, j, temp;
    for (i = 1; i < arrayLEN; i++) // 遍历数组下标从1到最后的元素
    {
        if (A[i - 1] > A[i]) // i下标的元素同前一个元素比较，如果前面的大，就要把后面的元素放入前面的序列中
        {
            temp = A[i]; // 存储后面较小的元素

            for (j = i - 1; j >= 0 && A[j] > temp; j--) // 依次遍历i下标之前的所有元素，如果有大于i下标的元素，则把前面的元素全部往后推
            {
                A[j + 1] = A[j];
            }
            A[j + 1] = temp; // 把之前i下标的元素放到第一个小于他的数后面
        }
    }
}
void shellSort(int A[], int n) // n为数组长度，这里是希尔排序，将数组下标为0的元素当成一个暂存区，来存放变量
{
    int i, j, d;
    for (d = n / 2; d >= 1; d = d / 2)
    {
        for (i = d + 1; i < n; i++)
        {
            if (A[i - d] > A[i])
            {
                A[0] = A[i];
            }
            for (j = i - d; j >= 0 && A[j] < A[0]; j -= d)
            {
                A[j + d] = A[j];
            }
            A[j] = A[0];
        }
    }
}

int work(int *A, int low, int high) // 快排中，对一次排序进行处理，最后返回pivot的位置
{
    int pivot = A[low];
    while (low < high)
    {
        while (A[high] >= pivot && low < high)
        {
            high--;
        }
        A[low] = A[high];
        while (A[low] < pivot && low < high)
        {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot; // 此时low的位置就是pivotPos;
    return low;
}
void quickSort(int *A, int low, int high)
{
    if (low < high) //低轨跳出的条件
    {
        int pivotPos = work(A, low, high);
        quickSort(A, low, pivotPos - 1);
        quickSort(A, pivotPos + 1, high);
    }
}
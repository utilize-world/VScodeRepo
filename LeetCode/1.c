#include <stdio.h>

int pivotIndex(int *nums, int numsSize) // 让pivot两边的数组元素之和相等
{
    int i, pivotPos = 0;
    int leftsum, totalsum = 0;
    for (i = 0; i < numsSize; i++)
    {
        totalsum += nums[i];
    }
    for (pivotPos = 0; pivotPos < numsSize; pivotPos++)
    {
        if (leftsum * 2 + nums[pivotPos] == totalsum)
        {
            return pivotPos;
        }
        leftsum += nums[pivotPos];
    }

    return -1;
}
void main()
{
    int num[6] = {1, 7, 3, 6, 5, 6};
    printf("%d\n", pivotIndex(num, 6));
}
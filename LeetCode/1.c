#include <stdio.h>

int pivotIndex(int *nums, int numsSize) //鎵惧埌鏁扮粍涓績涓嬫爣锛屼护pivot宸﹁竟涔嬪拰绛変簬鍙宠竟涔嬪拰锛屽鏋滄病鏈夎繑鍥�-1
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
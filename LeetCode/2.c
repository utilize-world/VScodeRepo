int searchInsert(int *nums, int numsSize, int target) // 有序数组找到目标值并输出下标
{
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] >= target)
            return i;
    }
    return numsSize;
}

int searchInsertDiv(int *nums, int numsSize, int target) // 二分法
{
    int i, low = 0;
    int mid;
    int high = numsSize - 1;
    while (low < high)
    {
        mid = low + (high - low) / 2; // 这是关键的一步
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            /* code */
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
    }
    if (nums[low] < target)
    {
        return low + 1;
    }
    else
        return low;
}
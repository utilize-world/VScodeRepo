#include <iostream>
#include <vector>

using namespace std;

class Solution // 找到数组中所有重复的数字
{
public:
    Solution()
    {
        nums = {2, 3, 1, 0, 2, 5, 3};
    }
    int findRepeatNumber(vector<int> &nums)
    {
        vector<int> temp(nums.size(), -1); // 初始化一个相同大小的数组,这里用的是索引对齐的方法，初始化数组的值应当设置一个特殊的值，如果默认是0
        // 检查到0的时候会认为重复，就会出错

        if (nums.empty())
        {
            return -1;
        }
        for (auto it = 0; it < nums.size(); it++)
        {
            if (temp[nums[it]] == nums[it])
            {
                return nums[it];
            }
            else
                temp[nums[it]] = nums[it];
        }

        return -1;
    }

public:
    vector<int> nums;
};

int main()
{
    Solution *A = new Solution();
    cout << A->findRepeatNumber(A->nums);
}

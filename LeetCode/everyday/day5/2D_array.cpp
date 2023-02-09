// 在一个 n *m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，
// 每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
    }
    bool divideSearch(vector<int> &array, int target)
    {
        int low, mid, high;
        low = 0;
        high = array.size() - 1;
        while (low < high)
        {
            mid = low + (low + high) / 2;
            if (array[mid] < target)
            {
                low = mid + 1;
            }
            else if (array[mid] > target)
            {
                high = mid - 1;
            }
            else
                return true;
        }
        return false;
    }
};
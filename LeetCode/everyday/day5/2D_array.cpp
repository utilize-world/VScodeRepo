// 在一个 n *m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，
// 每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include <iostream>
#include <vector>
using namespace std;

class Solution // 方法一，暴力遍历+二分
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        // 思路是先横向搜索，然后纵向
        int r_pos; // c_pos; // 定义横向边界用于纵向查找
        if (matrix.empty())
        {
            return false;
        }
        bool Isfind = divideSearch(matrix[0], target, r_pos);

        if (Isfind)
        {
            return true;
        }
        else if (r_pos == -1)
        {
            return false;
        }
        else
        {
            return ColumnSearch(matrix, r_pos, target);
        }
    }
    bool divideSearch(vector<int> &array, int target, int &pos)
    {
        int low, mid, high;
        low = 0;
        high = array.size() - 1;
        while (low < high)
        {
            mid = low + ((low + high) / 2 - low);
            if (array[mid] < target)
            {
                low = mid + 1;
            }
            else if (array[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                pos = mid;
                return true;
            }
        }
        if (low == high && array[low] == target) // 要求的值在右边界或者左边界
        {
            pos = low;
            return true;
        }
        else if (low == high && array[low] > target) // 要求的值小于右边界
        {
            pos = low - 1;
            return false;
        }
        else if (low == high && array[low] < target) // 要求的值大于右边界//考虑右边界是因为mid最多和low重合而不会和high重合
        {
            pos = low;
            return false;
        }
        if ((low > high && low > 0)) // 找不到要求的值，返回到上一个小于的
        {
            pos = low - 1;
            return false;
        }
        pos = -1; // 不能找到目标值
        return false;
    }
    bool ColumnSearch(vector<vector<int>> &array, int r_pos, /*int &c_pos*/ int target)
    {
        for (int i = 0; i <= r_pos; i++) // 列遍历
        {
            for (int j = 0; j < array.size() && array[j][i] <= target; j++) // 行遍历    这里遍历每一列(小于r_pos) 这里传统遍历，平均时间复杂度m*n
            {
                if (array[j][i] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
class searchTree
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
        {
            return false;
        }
        int c_size = matrix[0].size(); // 多少列
        int r_size = matrix.size();    // 多少行
        int i, j;
        i = r_size - 1; // 相当于两个指针
        j = 0;
        while (i >= 0 && j < c_size) // 注意等于号
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                i--;
            }
            else if (matrix[i][j] < target)
            {
                j++;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> matx = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 7;
    // Solution *A = new Solution();
    // cout << bool(A->findNumberIn2DArray(matx, target));
    searchTree *T = new searchTree();
    cout << T->findNumberIn2DArray(matx, target);
}

#include <iostream>
#include <string>
// 实现字符串的左旋，就是把字符串前N的字符移动到末尾
#include "stringFunc.h"
#include "stringFunc.cpp"
// string substr (size_t pos = 0, size_t len = npos) const; 用到提取子字符串的函数
using namespace std;
class Solution1
{
public:
    string reverseLeftWords(string s, int n)
    {
        string temp1 = s.substr(0, n);
        string temp2 = s.substr(n, s.length() - n);
        return temp2 + temp1;
    }
};

void test()
{
    Solution1 *A = new Solution1();
    string testString = "abcd efg123";
    Solution *B = new Solution();
    string result;
    result = A->reverseLeftWords(testString, 2);
    B->printString(result);
}

int main()
{
    test();
}
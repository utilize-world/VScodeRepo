#pragma once
#include <iostream>
#include <string>
#include "stringFunc.h"
string Solution ::replaceSpace(string &s) // 替换目标字符串
{
    /* string::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    } */
    string replaceString = "%20";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') // 双引号表示字符的时候出现报错，改成单字符就可以了
        {
            s.erase(i, 1);
            s.insert(i, replaceString);
        }
    }
    return s;
}
void Solution::printString(string s)
{
    for (auto i : s)
    {
        cout << i;
    }
}

// int main()
// {
//     string a = "abc abc 123123";
//     Solution *A = new Solution();
//     A->printString(A->replaceSpace(a));
// }
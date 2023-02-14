#include <iostream>
using namespace std;
const int MAXN = 100000;
const int k = 1000; // range(范围)
int a[MAXN], c[MAXN], ranked[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++c[a[i]];
    }
    for (int i = 1; i < k; ++i)
        c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; --i)
        ranked[--c[a[i]]] = a[i]; // 如果是i表达的是原数标号，a[i]就是排序后的正确序列
    for (int i = 0; i < n; ++i)
        cout << ranked[i] << endl;
    return 0;
}
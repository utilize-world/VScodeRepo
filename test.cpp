#include <stdio.h>
void test(int &x)
{
    x = 100;
    printf("the value of x is %d\n", x);
}

int main()
{
    int x = 1;
    printf("����testǰ,x=%d\n", x);
    test(x);
    printf("����test��,x=%d\n", x);
}
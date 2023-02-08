#include <stdio.h>
void test(int &x)
{
    x = 100;
    printf("the value of x is %d\n", x);
}

int main()
{
    int x = 1;
    printf("调用test前,x=%d\n", x);
    test(x);
    printf("调用test后,x=%d\n", x);
}
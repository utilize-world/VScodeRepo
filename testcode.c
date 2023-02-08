#include <stdio.h>
#include <stdlib.h>
#define arraySize 10
typedef struct testcode
{
    int ls[arraySize];
    int listLen;
} test;

void initTestcode(test *t)
{
    int i;
    for (i = 0; i < arraySize; i++)
        t->ls[i] = i;
    t->listLen = arraySize;
}

void insertList(test *t, int pos, int value)
{
    int len = t->listLen;
    if (pos < 0)
    {
        printf("error vlaue");
    }
    else
    {
        for (int i = len - 1; i > pos - 1; i--)
        {
            t->ls[i] = t->ls[i - 1];
        }
        t->ls[pos - 1] = value;
    }
}

void printdata(test *t)
{
    for (int i = 0; i < t->listLen; i++)
    {
        printf("%d", t->ls[i]);
    }
    printf("\n");
}
int main()
{
    test t;
    initTestcode(&t);
    printdata(&t);
    insertList(&t, 3, 5);
    printdata(&t);
}
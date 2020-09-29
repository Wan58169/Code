#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ret;
    int (*f)(int, int);
}MyNode;

int plus(int x, int y)
{
    return x+y;
}

int minus(int x, int y)
{
    return x-y;
}

int main()
{
    // MyNode mn;

    // mn.f = plus;
    // mn.ret = mn.f(1, 2);
    // printf("ret..%d\n", mn.ret);

    // mn.f = minus;
    // mn.ret = mn.f(3, 2);
    // printf("ret..%d\n", mn.ret);

    // int a[100] = {0};
    // int *a = (int *)malloc(sizeof(int)*100);
    // int aLen = sizeof(a);

    // printf("%d\n", aLen);
    printf("%d", sizeof(int));
    return 0;
}
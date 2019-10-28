#include <stdio.h>

void foo(int x);
static void bar(int x)
{
    printf("*");
    if(x > 0)
        bar(x-1)
        foo(x-1);
}
void foo(int x)
{
    if(x > 0)
        bar(x-1);
}

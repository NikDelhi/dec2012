#include <stdio.h>
#include <stdlib.h>

int* check(int a)
{
    int *t = (int*) malloc(sizeof(int));
    t = &a;
    return t;

}

int main()
{
    int *t;
    int c = 5;
    t = check(c);
    printf("%d\n", *t);	
    return 0;

}

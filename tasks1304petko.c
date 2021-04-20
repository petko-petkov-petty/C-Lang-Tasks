#include <stdio.h>

//task0
int sum(int a, int b)
{
    return a + b;
}

//task1
int isEven(int a)
{
    return !(a & 1);
}

//task2v1
int areSignsDifferent(int a, int b)
{
    return !!((a ^ b) >> (sizeof(int)*8 - 1));
}

//task2v2
int areSignsDifferent_v2(int a, int b)
{
    return ((a ^ b) < 0);
}

//task3
int swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

//task4v1
int add1(int a)
{
    return -(~a);
}

//task4v2
int add1_v2(int a)
{
    return (a - (~0));
}

//task5v1
int isPowOf2(int a)
{
    if(a != 0)
        for (int i = 1; i < sizeof(int)*8; i++)
            if(a == 1<<i)
                return 1;
    return 0;
}

//task5v2
int isPowOf2_v2(int a)
{
    return ((a & (a - 1)) == 0);
}

//task5v3
int isPowOf2_v3(int a)
{
    return ((a & (-a)) == a);
}

//task5bonus1
int isPowOf2_Bonus1(int a)
{
    if(!(a ^ 0))
        return 1;
    for (int i = 1; i < sizeof(int)*8; i++)
        if(!(a ^ 1<<i))
            return 1;
    return 0;
}

//task5bonus2
int whichPowOf2_Bonus2(int a)
{
    if(a != 0)
        for (int i = 1; i < sizeof(int)*8; i++)
            if(a == 1<<i)
                return i;
    return -1;
}

int main()
{
    int x, y;
    printf("\tEnter x: ");
    scanf("%d", &x);
    printf("\tEnter y: ");
    scanf("%d", &y);

    //task0
    printf("TASK 0\tSum of x and y: %d\n", sum(x, y));

    //task1
    printf("TASK 1\tIs x even: %s\n", isEven(x) ? "YES" : "NO");

    //task2
    printf("TASK 2\tAre signs of x and y different: %s\n", areSignsDifferent(x, y) ? "YES" : "NO");

    //task2v2
    printf("TASK 2b\tAre signs of x and y different: %s\n", areSignsDifferent_v2(x, y) ? "YES" : "NO");

    //task3
    swap(&x, &y);
    printf("TASK 3\tAfter swap x==%d y==%d\n", x, y);

    //task4
    printf("TASK 4\tx + 1 == %d\n", add1(x));

    //task4v2
    printf("TASK 4b\tx + 1 == %d\n", add1_v2(x));

    //task5
    printf("TASK 5\tIs x power of 2: %s\n", isPowOf2(x) ? "YES" : "NO");

    //task5v2
    printf("TASK 5b\tIs x power of 2: %s\n", isPowOf2_v2(x) ? "YES" : "NO");

    //task5v3
    printf("TASK 5c\tIs x power of 2: %s\n", isPowOf2_v3(x) ? "YES" : "NO");

    //task5bonus1
    printf("TASK B1\tIs x power of 2: %s\n", isPowOf2_Bonus1(x) ? "YES" : "NO");

    //task5bonus2
    printf("TASK B2\tWhich power of 2 is x: %d\n", whichPowOf2_Bonus2(x));

    return 0;
}
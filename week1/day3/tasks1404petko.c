#include <stdio.h>
#include <stdint.h>

//task1
void printHex(unsigned int x)
{
    printf("0x");

    if (x == 0) 
        printf("0");
    else
    {
        unsigned int y;
        int isLeadingZero = 1;

        for (int j = 0; j < sizeof(x)*8; j += 4)
        {
            y = x << j;
            y = y >> sizeof(x)*8 - 4;

            if (!y && !isLeadingZero)
                printf("0");
            else if (!y && isLeadingZero)
                continue;
            else if (y > 0 && y <10)
            {
                isLeadingZero = 0;
                printf("%c", '0' + y);
            }
            else
            {
                isLeadingZero = 0;                
                printf("%c", 'A' + y - 10);
            }
        }
    }

    printf("\n");
}

//task2
uint32_t rotate(uint32_t x)
{
    uint32_t y, z = 0u;

    for (int i = sizeof(x)*8 - 1; i >= 0; i--)
    {
        y = x << i;
        y = y >> (sizeof(x)*8 - 1);
        y = y << i;

        z |= y;
    }

    return z;
}

void printbin(unsigned);

int main()
{
    const int TEST1 = 0;
    const int TEST2 = 1;
    const int TEST3 = 10;
    const int TEST4 = 200000;

//task1
    printf("%d\t", TEST1);  printbin(TEST1);    printf("\t");   printHex(TEST1);
    printf("%d\t", TEST2);  printbin(TEST2);    printf("\t");   printHex(TEST2);
    printf("%d\t", TEST3);  printbin(TEST3);    printf("\t");   printHex(TEST3);
    printf("%d\t", TEST4);  printbin(TEST4);    printf("\t");   printHex(TEST4);

//task2
    printf("%d\t", TEST1);  printbin(TEST1);    printf("\t");   printbin(rotate(TEST1));    printf("\t%u\t", rotate(TEST1));    printf("\n");
    printf("%d\t", TEST2);  printbin(TEST2);    printf("\t");   printbin(rotate(TEST2));    printf("\t%u\t", rotate(TEST2));    printf("\n");
    printf("%d\t", TEST3);  printbin(TEST3);    printf("\t");   printbin(rotate(TEST3));    printf("\t%u\t", rotate(TEST3));    printf("\n");
    printf("%d\t", TEST4);  printbin(TEST4);    printf("\t");   printbin(rotate(TEST4));    printf("\t%u\t", rotate(TEST4));    printf("\n");

    return 0;
}

void printbin(unsigned int t)
{
    unsigned int mask;

    for (mask = 0x80000000; mask; mask = mask >> 1)
    printf("%d", !!(t & mask));

    return;
}
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<time.h>
#include<math.h>
#include<string.h>

#define LEN 2
#define POS 59

int const SIZE_OF_INT32_IN_BITS = sizeof(uint32_t) * 8;

// TASK 1A
int setBitAt_To0(uint32_t *u, size_t pos)
{
    if(pos >= 0 && pos < LEN * SIZE_OF_INT32_IN_BITS)
    {
        u[(int)floor(pos / SIZE_OF_INT32_IN_BITS)] &= (0xFFFFFFFF ^ (1 << (pos % (SIZE_OF_INT32_IN_BITS))));

        return 0; 
    }
    else
    {
        return -1;
    }
}

// TASK 1B
int setBitAt_To1(uint32_t *u, size_t pos)
{
    if(pos >= 0 && pos < LEN * SIZE_OF_INT32_IN_BITS)
    {
        u[(int)floor(pos / SIZE_OF_INT32_IN_BITS)] |= (0x0 ^ (1 << (pos % (SIZE_OF_INT32_IN_BITS))));

        return 0; 
    }
    else
    {
        return -1;
    }
}  

// TASK 1C
int setBitAt_To_(uint32_t *u, size_t pos, int val)
{
    if(pos >= 0 && pos < LEN * SIZE_OF_INT32_IN_BITS)
    {
        if(val==0)
        {
            return setBitAt_To0(u, pos);
        }
        else if(val==1)
        {
            return setBitAt_To1(u, pos);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

// TASK 1D
int getBitAt_(uint32_t *u, size_t pos)
{
    if(pos >= 0 && pos < LEN * SIZE_OF_INT32_IN_BITS)
    {
        if((u[(int)floor(pos / SIZE_OF_INT32_IN_BITS)] >> (pos % SIZE_OF_INT32_IN_BITS)) & (1 << 0))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int isPrime(int i);

// TASK 2
void erathosthenesSieve(uint32_t *u)
{
    for(int i = 0; i < LEN * SIZE_OF_INT32_IN_BITS; i++)
    {
        if(isPrime(i))
        {
            setBitAt_To1(u, i);
        }
        else
        {
            setBitAt_To0(u, i);
        }
    }
}

// TASK 3
void clearEvenBitsAndRaiseOddBits(uint32_t *u)
{
    for(int i = 0; i < LEN * SIZE_OF_INT32_IN_BITS; i++)
    {
        if(i%2==0)
        {
            setBitAt_To0(u, i);
        }
        else
        {
            setBitAt_To1(u, i);
        }
    }
}

// TASK 4
void createPattern(uint32_t *u)
{
    int count0s = 0;
    for(int i = 0; i < LEN * SIZE_OF_INT32_IN_BITS; )
    {
        setBitAt_To0(u, i);
        count0s++;
        i++;

        for(int j = count0s; j > 0; j--)
        {
            setBitAt_To1(u, i);
            i++;
        }
    }
}

void printSequence(uint32_t *);
void printArrow();

int main()
{
    // CREATE A DYNAMIC ARRAY
    uint32_t *u;
    u = (uint32_t *)malloc(LEN * sizeof(uint32_t));

    // FILL THE ARRAY WITH RANDOM NUMBERS
    printf("\nThe numbers in the array are: ");
    srand(time(NULL));
    for(int i = 0; i < LEN; i++)
    {
        u[i] = rand();
        printf("%d ", u[i]);
    }

    // PRINT THE NUMBERS IN THE ARRAY AS A SEQUENCE OF THE BITS OF EACH NUMBER ORDERED 0-31 | 32-63 | 64-...
    printSequence(u);   printArrow();   printf("The bit at position %d is %d. ", POS, getBitAt_(u, POS));

    // TASK 1A
    printf("Setting it to 0 %s", setBitAt_To0(u, POS) ? "FAILED!" : "DONE!");

    printSequence(u);   printArrow();   printf("The bit at position %d is %d. ", POS, getBitAt_(u, POS));

    // TASK 1B
    printf("Setting it to 1 %s", setBitAt_To1(u, POS) ? "FAILED!" : "DONE!");

    printSequence(u);   printArrow();   printf("The bit at position %d is %d. ", POS, getBitAt_(u, POS));

    // TASK 1C
    printf("Setting it to %d %s", 0, setBitAt_To_(u, POS, 0) ? "FAILED!" : "DONE!");
 
    printSequence(u);   printArrow();   printf("The bit at position %d is %d. ", POS, getBitAt_(u, POS));

    // TASK 1D
    printf("Setting it to %d %s", 1, setBitAt_To_(u, POS, 1) ? "FAILED!" : "DONE!");

    printSequence(u);   printArrow();   printf("The bit at position %d is %d. ", POS, getBitAt_(u, POS));

    // TASK 2
    erathosthenesSieve(u);
    printf("\nCreating the Erathosthenes sieve (the bits on a position that is a prime number (including 0, 1, 2) are set to 1, the bits on a position that is not a prime number are set to 0)");

    printSequence(u);

    // TASK 3
    clearEvenBitsAndRaiseOddBits(u);
    printf("\nClearing the even bits and raising the odd bits");

    printSequence(u);

    // TASK 4
    createPattern(u);
    printf("\nCreating the pattern");

    printSequence(u);

    printf("\n");

    return 0;
}

int isPrime(int i)
{
    if(i == 0 || i == 1)
    {
        return 1;
    }
    else
    {
        for(int j = 2; j <= i/2; j++)
        {
            if(i % j == 0)
            {
                return 0;
            }
        }

        return 1;
    }
}

void printSequence(uint32_t *u)
{
    printf("\nThe numbers in the array as a sequence of bits: ");

    for (size_t i = 0; i < LEN * SIZE_OF_INT32_IN_BITS; i++)
    {
        if (i > 0 && i % SIZE_OF_INT32_IN_BITS == 0)
        {
            printf("| ");
        }

        printf("%d ", getBitAt_(u, i));
    }
}

void printArrow()
{
    printf("\n");

    int len = strlen("The numbers in the array as a sequence of bits: ") + 2 * POS + 2 * ((int)floor(POS / SIZE_OF_INT32_IN_BITS));

    for (size_t i = 0; i < len; i++)
    {
        printf(" ");
    }

    printf("^\n");
}
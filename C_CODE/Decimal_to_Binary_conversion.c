#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void DectoBin_2(int number)
{
    unsigned int mask = 1u << 16; //31
    int cnt = 0;
    while (mask >>= 1)
    {
        printf("%d", number & mask? 1 : 0);
        cnt ++;
        if (!(cnt % 4))
        {
            putchar(' ');
        }
    }
}

long long DectoBin(int Dec)
{
    long long count = 1;
    long long sum = 0;
    char mod = 0;
    while (Dec)
    {
        mod = Dec % 2;
        Dec /= 2;
        sum += mod * count;
        count *= 10;
    }
    return sum;
}

int BintoDec(long long Bin)
{
    int Dec = 0;
    int count = 0;
    while (Bin)
    {
        Dec += (Bin & 1) * pow(2, count);
        Bin /= 10;
        count++;
    }
    return Dec;
}

int main(void)
{
    long long number;
    scanf("%I64d", &number);

    printf("Dec:%d\n", BintoDec(number));
    printf("Bin:%I64d\n", DectoBin(number));
}

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    printf("random number%i", n);
    return (0);
}

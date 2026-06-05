#include <stdio.h>

int mad(int);

void main(void)
{
    int NUM, RES;

    printf("\nPon un numero: ");
    scanf("%d", &NUM);

    RES = mad(NUM);

    printf("\nEl divisor mas grande de %d es: %d", NUM, RES);
}

int mad(int N1)
{
    int I = (N1 / 2);

    while (N1 % I)
        I--;

    return I;
}
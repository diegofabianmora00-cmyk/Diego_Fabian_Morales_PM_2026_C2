#include <stdio.h>

void main(void)
{
    int DIS, TIE;
    float BIL;

    printf("Distancia entre ciudades: ");
    scanf("%d %d", &DIS, &TIE);

    if ((DIS * 2 > 500) && (TIE > 10))
        BIL = DIS * 2 * 0.19 * 0.8;
    else
        BIL = DIS * 2 * 0.19;

        printf("\n\nCosto de billete: %7.2f", BIL);
}
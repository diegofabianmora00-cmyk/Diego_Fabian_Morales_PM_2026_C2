#include <stdio.h>

void main(void)
{
int I;
float SAL, NOM;

    NOM = 0;

    for (I = 1; I <= 15; I++)
    {
    printf("\ningrsar el salario del profesor %d:\t", I);
    scanf("%f", &SAL);

    NOM = NOM + SAL;
    }

    printf("\nel total de la nomina es: %.2f", NOM);
}
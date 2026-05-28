#include <stdio.h>

void main(void)
{
    int I = 0;
    float SAL, PRO, NOM = 0;

printf("ingresar el salario del profesor:\t");

   
    scanf("%f", &SAL);

    do
    {
    NOM = NOM + SAL;
    I = I + 1;

printf("ingresar el salario del profesor -0 para terminar-:\t");
    scanf("%f", &SAL);

    }
    while (SAL);

    PRO = NOM / I;

printf("\nNómina: %.2f \t Promedio: %.2f", NOM, PRO);
}
#include <stdio.h>

void main(void)
{
    int I, NUM;
    long FAC;

printf("\ningresar el numero: ");
    scanf("%d", &NUM);

    if (NUM >= 0)
    {
    FAC = 1;

    for (I = 1; I <= NUM; I++)
    FAC *= I;

printf("\nel factorial de %d es: %ld", NUM, FAC);
    }
    else
printf("\nERROR");
}
#include <stdio.h>

void main(void)
{
int I, N, NUM, SUM;
    SUM = 0;

printf("ingresar el numero de datos:\t");
scanf("%d", &N);

    for (I = 1; I <= N; I++)
    {
printf("ingresar el dato numero %d:\t", I);
scanf("%d", &NUM);

    if (NUM > 0)
    SUM = SUM + NUM;
    }

    printf("\nLa suma de los numeros es: %d", SUM);
}
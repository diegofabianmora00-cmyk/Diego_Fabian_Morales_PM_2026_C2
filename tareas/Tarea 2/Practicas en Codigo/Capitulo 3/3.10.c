#include <stdio.h>
#include <math.h>

void main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

printf("ingresar el numero de datos que se van a procesar:\t");
    scanf("%d", &N);

    if (N > 0)
    {
    for (I = 1; I <= N; I++)
        {
printf("\nIngrese el número %d: ", I);
    scanf("%d", &NUM);

    if (NUM)
    if (pow(-1, NUM) > 0)
    SPA = SPA + NUM;
    else
        {
    SIM = SIM + NUM;
    CIM++;
        }

        }

printf("\nla suma de numeros pares es: %d", SPA);
printf("\nel promedio de numeros impares es: %5.2f", (float)SIM / CIM);

    }
    else

printf("\nel valor N es incorrecto");
}
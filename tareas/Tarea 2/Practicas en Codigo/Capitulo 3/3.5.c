#include <stdio.h>

void main(void)
{
    float PAG, SPA = 0;

printf("ingresar el primer pago:\t");
    scanf("%f", &PAG);


    do
    {
    SPA = SPA + PAG;

printf("ingresar el siguiente pago -0 para terminar-:\t");
    scanf("%f", &PAG);
    }
    while (PAG);

printf("\ntotal de pagos del mes es: %.2f", SPA);
}
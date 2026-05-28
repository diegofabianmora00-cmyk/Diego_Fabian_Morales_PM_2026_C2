#include <stdio.h>



void main(void)
{
float PAG, SPA;

SPA = 0;

printf("ingresar el primer pago:\t");
    scanf("%f", &PAG);

while (PAG)
   
    {
    SPA = SPA + PAG;

printf("ingresar el siguiente pago:\t");
    scanf("%f", &PAG);

       
    }

printf("\ntotal de pagos del mes es: %.2f", SPA);
}
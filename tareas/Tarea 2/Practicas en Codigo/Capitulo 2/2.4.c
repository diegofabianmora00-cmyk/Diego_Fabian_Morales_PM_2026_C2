#include <stdio.h>

void main(void)
{
float PRE, NPR;
    printf("Precio de produccto ");

scanf("%f", &PRE);

if (PRE < 1500)
NPR = PRE * 1.11;

else NPR = PRE * 1.08; 

    printf("\nNuevo Precio: %8.2f", NPR);

}
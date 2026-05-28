#include <stdio.h>

int main(void)
{
    float PRE, NPR;

    printf("ingrese el precio:");
    scanf("%f", &PRE);

    if (PRE > 1500)
    {
    NPR = PRE * 1.11;
        printf("\n Nuevo: %7.2f", NPR);
    }

return 0;
}
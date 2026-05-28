#include <stdio.h>

int main(void)
{
    float PRO;

    printf("Promedio del estudiante:");
    scanf("%f", &PRO);

    if (PRO >= 6.0)
        printf("\nAprobado");
    else
        printf("\nReprobado");

    return 0;
}
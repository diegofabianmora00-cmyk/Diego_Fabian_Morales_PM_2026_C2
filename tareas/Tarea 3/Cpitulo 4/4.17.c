#include <stdio.h>

void Mayor(float, float, float);

void main(void)
{
    int I;
    float GOL, PAC, CAR, AGOL = 0, APAC = 0, ACAR = 0;

    for (I = 1; I <= 12; I++)
    {
        printf("\n\nPon las lluvias del mes %d", I);
        printf("\nDatos de Golfo, Pacifico y Caribe: ");
        scanf("%f %f %f", &GOL, &PAC, &CAR);

        AGOL += GOL;
        APAC += PAC;
        ACAR += CAR;
    }

    printf("\n\nPromedio de lluvias en Golfo: %6.2f", (AGOL / 12));
    printf("\nPromedio de lluvias en Pacifico: %6.2f", (APAC / 12));
    printf("\nPromedio de lluvias en Caribe: %6.2f\n", (ACAR / 12));

    Mayor(AGOL, APAC, ACAR);
}

void Mayor(float R1, float R2, float R3)
{
    if (R1 > R2)
        if (R1 > R3)
            printf("\nLa region con mas lluvia es Golfo. Promedio: %6.2f", R1 / 12);
        else
            printf("\nLa region con mas lluvia es Caribe. Promedio: %6.2f", R3 / 12);
    else if (R2 > R3)
        printf("\nLa region con mas lluvia es Pacifico. Promedio: %6.2f", R2 / 12);
    else
        printf("\nLa region con mas lluvia es Caribe. Promedio: %6.2f", R3 / 12);
}
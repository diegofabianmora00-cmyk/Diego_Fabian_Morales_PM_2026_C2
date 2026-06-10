#include <stdio.h>
/* Profesor, este programa toma demasiado tiempo y solo es un ejemplo  */
void main(void)
{
    int X = 3, Y = 7, Z[5] = {2, 4, 6, 8, 10};

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    int *IX;

    IX = &X;
    Y = *IX;
    *IX = 1;

    printf("\nValores actuales -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &Z[2];
    Y = *IX;
    *IX = 15;

    printf("\nDatos modificados -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *IX + 5;
    *IX = *IX - 5;

    printf("\nEstado del arreglo -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    ++*IX;
    *IX += 1;

    printf("\nRevision de variables -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *(IX + 1);
    Y = *IX;

    printf("\nContenido actualizado -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 1;
    Y = *IX;

    printf("\nResultado obtenido -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 4;

    printf("\nNueva revision -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &X;
    IX = IX + 1;
    X = *IX;

    printf("\nValores finales -> X = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
}
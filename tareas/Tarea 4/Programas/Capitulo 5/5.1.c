#include <stdio.h>

void main(void)
{
    int I, NUM, CUE = 0;
    int ARRE[10];

    for (I = 0; I < 10; I++)
    {
        printf("Escriba el dato de la posicion %d: ", I + 1);
        scanf("%d", &ARRE[I]);
    }

    printf("\n\nIndique el numero que desea localizar: ");
    scanf("%d", &NUM);

    for (I = 0; I < 10; I++)
        if (ARRE[I] == NUM)
            CUE++;

    printf("\n\nEl valor %d aparece %d ocasiones dentro del arreglo", NUM, CUE);
}
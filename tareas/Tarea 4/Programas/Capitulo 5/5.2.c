#include <stdio.h>

void main(void)
{
    int ELE[5] = {0};
    int I, VOT;

    printf("Primer voto (0 para finalizar): ");
    scanf("%d", &VOT);

    while (VOT)
    {
        if ((VOT > 0) && (VOT < 6))
            ELE[VOT-1]++;
        else
            printf("\nEl numero indicado no es valido.\n");

        printf("Registre otro voto (0 para finalizar): ");
        scanf("%d", &VOT);
    }

    printf("\n\nConteo de la votacion\n");

    for (I = 0; I <= 4; I++)
        printf("\nPrticipante %d: %d", I + 1, ELE[I]);
}
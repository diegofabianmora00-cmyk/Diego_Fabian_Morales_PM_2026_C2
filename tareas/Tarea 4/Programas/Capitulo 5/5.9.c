#include <stdio.h>

/* tenia un problema parecido al progrmaa anterior, donde decia LECTURA */

const int MAX = 100;

void Lectura(int *, int);
int Busca(int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Indique el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nEscriba el valor que desea encontrar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);

    if (RES)
        printf("\nEl dato fue encontrado en la posicion %d", RES);
    else
        printf("\nEl dato no aparece en el arreglo");
}

void Lectura(int A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Capture el numero %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int K)
{
    int I = 0, BAN = 0, RES;

    while (I < T && !BAN)
        if (A[I] == K)
            BAN++;
        else
            I++;

    if (BAN)
        RES = I + 1;
    else
        RES = BAN;

    return (RES);
}
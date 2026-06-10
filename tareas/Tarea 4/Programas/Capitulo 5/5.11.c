#include <stdio.h>

const int MAX = 100;

void Lectura(int *, int);
int Binaria(int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Indique la cantidad de elementos: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nEscriba el valor que desea encontrar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);

    if (RES)
        printf("\nEl valor fue localizado en la posicion: %d", RES);
    else
        printf("\nNo se encontro el valor dentro del arreglo");
}

void Lectura(int A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Capture el dato %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
{
    int ELE, IZQ = 0, CEN, DER = T - 1, BAN = 0;

    while ((IZQ <= DER) && (!BAN))
    {
        CEN = (IZQ + DER) / 2;

        if (E == A[CEN])
            BAN = CEN;
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return (BAN);
}
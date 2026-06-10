

#include <stdio.h>

    /* 

el codigo como estaba en el libro no me funcionaba de ninguna manera, investigue como pude y le arregle algunas partes,
no se si me quedo bien: Le arreglE la funcion Imprime para que reciba bien el arreglo, tambien quite el 1 porque no es primo 
y  acomode el conteo
para que guarde bien los 100 numeros primos, no se si me quedo bien, entiendo si no me lo acepta 

    */

#define TAM 100

void Imprime(int [], int);
void Primo(int, int *);

void main(void)
{
    int P[TAM] = {2};
    int FLA, J = 1, PRI = 3;

    while (J < TAM)
    {
        FLA = 1;

        Primo(PRI, &FLA);

        if (FLA)
        {
            P[J] = PRI;
            J++;
        }

        PRI += 2;
    }

    Imprime(P, TAM);

    return 0;
}

void Primo(int A, int *B)
{
    int DI = 2;

    while (*B && (DI <= (A / 2)))
    {
        if ((A % DI) == 0)
            *B = 0;

        DI++;
    }
}

void Imprime(int Primos[], int T)
{
    int I;

    for (I = 0; I < T; I++)
        printf("\nPrimo #%d: %d", I + 1, Primos[I]);
}
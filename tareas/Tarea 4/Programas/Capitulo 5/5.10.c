#include <stdio.h>
/* otra vez con el mismo fallo (me estoy volviendo loco), lo mismo, la funcion de lectura, que se declara mal

. */
const int MAX = 100;

void Lectura(int *, int);
int Busca(int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Indique cuantos datos tendra el arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el valor que desea localizar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);

    if (RES)
        printf("\nEl valor fue localizado en la posicion %d", RES);
    else
        printf("\nNo se encontro el valor dentro del arreglo");
}

void Lectura(int A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Escriba el dato %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int E)
{
    int RES, I = 0, BAN = 0;

    while ((I < T) && (E >= A[I]) && !BAN)
        if (A[I] == E)
            BAN++;
        else
            I++;

    if (BAN)
        RES = I + 1;
    else
        RES = BAN;

    return (RES);
}
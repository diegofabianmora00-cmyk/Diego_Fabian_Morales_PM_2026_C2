#include <stdio.h>

/* 

   Aqui le tuve que cambiar el nombre alas variables, por que usar el "::" antes de una variable parece que no funciona en mi
   compilador

*/

void f1(void);
int K = 5;

int main(void)
{
    int I;

    for (I = 1; I <= 3; I++)
        f1();

    return 0;
}

void f1(void)
{
    int Klocal = 2;

    Klocal += Klocal;

    printf("\nEl valor de la variable local ahora es: %d", Klocal);

    K = K + Klocal;

    printf("\nEl valor actual de la variable global es: %d", K);
}
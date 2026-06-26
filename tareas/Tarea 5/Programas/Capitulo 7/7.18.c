#include <stdio.h>

void inverso(char *);

void main(void)
{
    char fra[50];

    printf("\nColocar la linea de texto: ");
    gets(fra);

    printf("\nLa linea de texto al inverso: ");
    inverso(fra);
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
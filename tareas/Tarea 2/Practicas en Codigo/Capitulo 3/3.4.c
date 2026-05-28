#include <stdio.h>
#include <math.h>

void main(void)
{
int NUM;
long CUA, SUC = 0;

printf("\ningresar un numero entero -0 para terminar-:\t");
    scanf("%d", &NUM);

    while (NUM)
    
    {
    CUA = pow(NUM, 2);

printf("%d al cuadrdo es: %ld", NUM, CUA);

    SUC = SUC + CUA;

printf("\ingresar un numero entero -0 para terminar-:\t");
        scanf("%d", &NUM);
    }

printf("\nLa suma es %ld", SUC);
}
#include <stdio.h>
#include <ctype.h>

void main(void)
{
    char p1;

    printf("\nColoca un valor para ver si es un digito: ");
    p1 = getchar();
    if (isdigit(p1))
        printf("%c es un digito \n", p1);
    else
        printf("%c no es un digito \n", p1);

    fflush(stdin);
    printf("\nColoca un valor para ver si es una letra: ");
    p1 = getchar();
    if (isalpha(p1))
        printf("%c es una letra \n", p1);
    else
        printf("%c no es una letra \n", p1);

    fflush(stdin);
    printf("\nColoca un valor para ver si es una letra minuscula: ");
    p1 = getchar();
    if (isalpha(p1))
        if (islower(p1))
            printf("%c es una letra minuscula \n", p1);
        else
            printf("%c no es una letra minuscula \n", p1);
    else
        printf("%c no es una letra \n", p1);

    fflush(stdin);
    printf("\nColoca una letra para convertirla de mayuscula a minuscula: ");
    p1 = getchar();
    if (isalpha(p1))
        if (isupper(p1))
            printf("%c fue convertida a minuscula \n", tolower(p1));
        else
            printf("%c es una letra minuscula \n", p1);
    else
        printf("%c no es una letra \n", p1);
}
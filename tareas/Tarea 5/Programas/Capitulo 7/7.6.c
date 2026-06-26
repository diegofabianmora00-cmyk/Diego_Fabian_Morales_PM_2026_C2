#include <stdio.h>
#include <string.h>

void main(void)
{
    char *cad0 = "Hola Mexico";
    char cad1[20], cad2[20], cad3[20] = ", buenos dias!!!";

    strcpy(cad1, cad0);
    printf("\nPrueba de strcpy. copia cad0 a cad1: %s\n", cad1);

    strcpy(cad1, cad3);
    printf("\nPrueba de strcpy. copia cad3 a cad1: %s\n", cad1);

    strcpy(cad1, "XX");
    printf("\nPrueba de strcpy. copia XX a cad1: %s\n", cad1);

    strncpy(cad2, cad0, 4);
    cad2[4] = '\0';
    printf("\nPrueba de strncpy. copian 4 caracteres de cad0 a cad2: %s\n", cad2);

    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("\nPrueba de strncpy. copian 3 caracteres de cad3 a cad2: %s\n", cad2);

    strcat(cad0, cad3);
    printf("\nPrueba de strcat. Se agrega cad3 a cad0: %s\n", cad0);

    strcat(cad1, " YY");
    printf("\nPrueba de strcat. Se agrega YY a cad1: %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("\nPrueba de strncat. Se agregan 4 caracteres de cad0 a cad2: %s\n", cad2);

    cad0 = strstr(cad0, "Mexico");
    printf("\nPrueba de strstr. Se busca Mexico dentro de cad0: %s\n", cad0);

    cad0 = strstr(cad0, "Guatemala");
    printf("\nPrueba de strstr. Se busca Guatemala dentro de cad0: %s\n", cad0);
}
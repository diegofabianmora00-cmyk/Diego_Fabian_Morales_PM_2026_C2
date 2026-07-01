#include <stdio.h>

int main(void)
{
    int p1;
    FILE *ar;

    if ((ar = fopen("arc.txt", "r")) != NULL)  // ← sin ; al final
    {
        while (!feof(ar))
        {
            p1 = fgetc(ar);
            putchar(p1);   // ← dentro del while
        }
        fclose(ar);
    }
    else                   // ← else justo después del bloque
    {
        printf("No se puede abrir el archivo\n");
    }
return 0 ;
}

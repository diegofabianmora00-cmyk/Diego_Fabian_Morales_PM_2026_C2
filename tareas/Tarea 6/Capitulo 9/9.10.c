#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *);

void main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "r+")) != NULL)
        modifica(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
}

void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("\nColoca el numero de registro a modificar: ");
    scanf("%d", &d);
    fseek(ap, (d-1)*sizeof(alumno), 0);
    fread(&alu, sizeof(alumno), 1, ap);
    printf("\nColoca el nuevo promedio del alumno: ");
    scanf("%f", &alu.promedio);
    fseek(ap, (d-1)*sizeof(alumno), 0);
    fwrite(&alu, sizeof(alumno), 1, ap);
}
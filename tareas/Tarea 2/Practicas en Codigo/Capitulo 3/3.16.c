#include <stdio.h>

void main(void)
{
int I, MAT, MAMAT, MEMAT;
float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;

printf("ingresar la matricula del primer estudiante:\t");
    scanf("%d", &MAT);

    while (MAT)
    {
    SUM = 0;

    for (I = 1; I <= 5; I++)
        {
printf("\t ingresar la calificacion %d del estudiante: ", I);
    scanf("%f", &CAL);

    SUM += CAL;
        }

    PRO = SUM / 5;

printf("\nMatricula:%d\tPromedio:%5.2f", MAT, PRO);

    if (PRO > MAPRO)
        {
    MAPRO = PRO;
    MAMAT = MAT;
        }

    if (PRO < MEPRO)
        {
    MEPRO = PRO;
     MEMAT = MAT;
        }

printf("\ningrear la matrícula del siguiente estudiante: ");
    scanf("%d", &MAT);
    }

printf("\n\nAlumno con mejor promedio:\t%d\t%5.2f", MAMAT, MAPRO);

printf("\n\nAlumno con peor promedio:\t%d\t%5.2f", MEMAT, MEPRO);
}
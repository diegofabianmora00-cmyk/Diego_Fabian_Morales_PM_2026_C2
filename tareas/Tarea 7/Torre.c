#include <stdio.h>
#include <math.h>
 
void hanoi(int n, char ini, char fin, char ayu, FILE *archivo, int *contador);
 
int main(){
    int dis;
    do {
        printf("Cuantos discos quiere: ");
        scanf("%d", &dis);
        if(dis <= 0)
            printf("No puede ser menor que 0\n");
        else if(dis > 30)
            printf("Demasiado alto\n");
    }  while (dis <= 0 || dis > 30);
 
    FILE *archivo = fopen("movimientos.txt", "w");
    if(archivo == NULL){
        printf("Error: no se pudo crear el archivo\n");
        return 1;
    }
 
    int contador = 0;
 
    printf("\nMovimiento\n");
    hanoi(dis, 'A', 'B', 'C', archivo, &contador);
 
    fclose(archivo);
 
    long total_movimientos = (1L << dis) - 1;
    printf("Total de movimientos: %ld\n", total_movimientos);
    printf("Los movimientos se guardaron en 'movimientos.txt'\n");
 
    return 0;
}
 
void hanoi(int n, char ini, char fin, char ayu, FILE *archivo, int *contador){
    if(n == 1){
        (*contador)++;
        printf("Mover disco 1 de %c a %c\n", ini, fin);
        fprintf(archivo, "%d. Mover disco 1 de %c a %c\n", *contador, ini, fin);
        return;
    }
    hanoi(n - 1, ini, ayu, fin, archivo, contador);
 
    (*contador)++;
    printf("Mover disco %d de %c a %c\n", n, ini, fin);
    fprintf(archivo, "%d. Mover disco %d de %c a %c\n", *contador, n, ini, fin);
 
    hanoi(n - 1, ayu, fin, ini, archivo, contador);
}
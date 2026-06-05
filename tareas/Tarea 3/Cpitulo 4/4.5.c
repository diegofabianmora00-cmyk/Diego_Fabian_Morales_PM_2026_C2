#include <stdio.h>

/* 
    lo mismo, tambien le tuve que cambiar el hecho de que empezaba con un Void, le puse un int, y tambien le puse un return, 
    ya que el programa no se ejecutaba, y me decia que no se podia convertir de void a int, entonces le puse un return, y ahora 
    si se ejecuta el programa bien
    
*/

int cubo(int); 

int main(void)
{
    int I;

    for (I = 1; I <= 10; I++)
        printf("\nl cubo del numero es: %d", cubo(I));
       

    return 0;
}

int cubo(int K) 
{
    return (K * K * K);
}
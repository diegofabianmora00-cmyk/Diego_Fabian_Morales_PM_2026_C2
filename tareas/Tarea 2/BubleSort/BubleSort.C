#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Cantidad de numeros: ");
    scanf("%d", &n);

    int numeros[n];

    for(i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    printf("Ordenados:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}
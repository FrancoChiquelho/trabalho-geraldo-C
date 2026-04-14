#include <stdio.h>

int main() {
    int inicio, fim, pares = 0;
    scanf("%d %d", &inicio, &fim);
    for (int i = inicio; i <= fim; i++) {
        if (i % 2 == 0) pares++;
    }
    printf("Numeros pares no intervalo: %d\n", pares);
    return 0;
}
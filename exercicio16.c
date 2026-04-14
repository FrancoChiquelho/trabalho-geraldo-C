#include <stdio.h>

int main() {
    float nota, soma = 0;
    int contador = 0;
    while (1) {
        scanf("%f", &nota);
        if (nota == -1) break;
        soma += nota;
        contador++;
    }
    if (contador > 0) printf("Media: %.2f\n", soma / contador);
    return 0;
}
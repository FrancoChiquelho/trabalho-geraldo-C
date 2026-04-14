#include <stdio.h>

int main() {
    int num, soma = 0;
    do {
        scanf("%d", &num);
        if (num > 0) {
            soma += num;
        }
    } while (num != 0);
    printf("Soma: %d\n", soma);
    return 0;
}
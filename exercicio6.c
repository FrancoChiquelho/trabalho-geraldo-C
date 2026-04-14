#include <stdio.h>

int main() {
    int opcao;
    float temp;
    do {
        printf("1. Celsius -> Fahrenheit\n2. Fahrenheit -> Celsius\n0. Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            scanf("%f", &temp);
            printf("%.2f F\n", (temp * 9 / 5) + 32);
        } else if (opcao == 2) {
            scanf("%f", &temp);
            printf("%.2f C\n", (temp - 32) * 5 / 9);
        }
    } while (opcao != 0);
    return 0;
}
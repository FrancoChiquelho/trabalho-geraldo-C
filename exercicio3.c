#include <stdio.h>

int main() {
    int opcao;
    float a, b;
    do {
        printf("1.Soma  2.Subtracao  3.Multiplicacao  4.Divisao  0.Sair\n");
        scanf("%d", &opcao);
        if (opcao >= 1 && opcao <= 4) {
            scanf("%f %f", &a, &b);
            switch(opcao) {
                case 1: printf("Resultado: %.2f\n", a + b); break;
                case 2: printf("Resultado: %.2f\n", a - b); break;
                case 3: printf("Resultado: %.2f\n", a * b); break;
                case 4: 
                    if (b != 0) printf("Resultado: %.2f\n", a / b);
                    break;
            }
        }
    } while (opcao != 0);
    return 0;
}
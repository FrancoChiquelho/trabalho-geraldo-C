#include <stdio.h>

int main() {
    int opcao, num;
    float a, b;
    do {
        printf("1. Calculadora (+)\n2. Tabuada\n3. Media de 2 notas\n4. Par/Impar\n0. Sair\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                scanf("%f %f", &a, &b);
                printf("Soma: %.2f\n", a + b);
                break;
            case 2:
                scanf("%d", &num);
                for(int i = 1; i <= 10; i++) printf("%d x %d = %d\n", num, i, num * i);
                break;
            case 3:
                scanf("%f %f", &a, &b);
                printf("Media: %.2f\n", (a + b) / 2);
                break;
            case 4:
                scanf("%d", &num);
                printf(num % 2 == 0 ? "Par\n" : "Impar\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}
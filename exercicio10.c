#include <stdio.h>

int main() {
    int opcao, num;
    do {
        printf("1. Tabuada\n2. Calculadora basica\n3. Verificacao Par/Impar\n0. Sair\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                scanf("%d", &num);
                for (int i = 1; i <= 10; i++) printf("%d x %d = %d\n", num, i, num * i);
                break;
            case 2:
                printf("Calculadora selecionada.\n");
                break;
            case 3:
                scanf("%d", &num);
                printf(num % 2 == 0 ? "Par\n" : "Impar\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}
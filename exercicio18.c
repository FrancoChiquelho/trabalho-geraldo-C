#include <stdio.h>

int main() {
    int opcao, num;
    do {
        printf("1. Verificar Paridade\n2. Sinal do numero\n3. Mostrar tabuada\n0. Sair\n");
        scanf("%d", &opcao);
        if (opcao >= 1 && opcao <= 3) {
            scanf("%d", &num);
            switch(opcao) {
                case 1: printf(num % 2 == 0 ? "Par\n" : "Impar\n"); break;
                case 2: 
                    if (num > 0) printf("Positivo\n");
                    else if (num < 0) printf("Negativo\n");
                    else printf("Zero\n");
                    break;
                case 3: 
                    for (int i = 1; i <= 10; i++) printf("%d x %d = %d\n", num, i, num * i); 
                    break;
            }
        }
    } while (opcao != 0);
    return 0;
}
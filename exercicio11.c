#include <stdio.h>

int main() {
    int opcao, sub_opcao;
    do {
        printf("1. Matematica\n2. Conversoes\n0. Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("--- Matematica ---\n1. Soma\n2. Subtracao\n");
            scanf("%d", &sub_opcao);
        } else if (opcao == 2) {
            printf("--- Conversoes ---\n1. Metros -> Centimetros\n2. Kg -> Gramas\n");
            scanf("%d", &sub_opcao);
        }
    } while (opcao != 0);
    return 0;
}
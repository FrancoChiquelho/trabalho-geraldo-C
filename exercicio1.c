#include <stdio.h>

int main() {
    int opcao;
    do {
        printf("1. Saudacao\n2. Mostrar um numero\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Ola! Bem-vindo.\n");
                break;
            case 2:
                printf("Numero: 100\n");
                break;
            case 0:
                break;
        }
    } while (opcao != 0);
    return 0;
}
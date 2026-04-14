#include <stdio.h>

int main() {
    int opcao;
    float saldo = 500.0, valor;
    do {
        printf("1. Consultar Saldo\n2. Depositar\n3. Levantar\n0. Sair\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Saldo: %.2f\n", saldo);
                break;
            case 2:
                scanf("%f", &valor);
                if (valor > 0) saldo += valor;
                break;
            case 3:
                scanf("%f", &valor);
                if (valor > 0 && valor <= saldo) saldo -= valor;
                break;
        }
    } while (opcao != 0);
    return 0;
}
#include <stdio.h>

int main() {
    int secreto = 55, palpite, tentativas = 0;
    do {
        scanf("%d", &palpite);
        tentativas++;
    } while (palpite != secreto);
    printf("Acertou! Numero de tentativas: %d\n", tentativas);
    return 0;
}
#include <stdio.h>

int main() {
    int secreto = 73, palpite;
    do {
        scanf("%d", &palpite);
    } while (palpite != secreto);
    printf("Acertou!\n");
    return 0;
}
#include <stdio.h>

int main() {
    int num;
    do {
        scanf("%d", &num);
        if (num != 0) {
            if (num % 2 == 0) {
                printf("Par\n");
            } else {
                printf("Impar\n");
            }
        }
    } while (num != 0);
    return 0;
}
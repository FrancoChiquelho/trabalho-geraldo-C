#include <stdio.h>

int main() {
    int num;
    long long fatorial = 1;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        fatorial *= i;
    }
    printf("Fatorial: %lld\n", fatorial);
    return 0;
}
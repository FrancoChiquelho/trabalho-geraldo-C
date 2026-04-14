#include <stdio.h>

int main() {
    int num, res;
    scanf("%d", &num);
    for (int i = 1; i <= 10; i++) {
        res = num * i;
        printf("%d x %d = %d (%s)\n", num, i, res, (res % 2 == 0) ? "Par" : "Impar");
    }
    return 0;
}
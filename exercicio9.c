#include <stdio.h>

int main() {
    float nota;
    do {
        scanf("%f", &nota);
    } while (nota < 0 || nota > 20);

    if (nota < 10) printf("Insuficiente\n");
    else if (nota < 14) printf("Suficiente\n");
    else if (nota < 18) printf("Bom\n");
    else printf("Muito Bom\n");
    
    return 0;
}
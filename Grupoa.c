#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50], categoria[50];
    int estado; // 1-Ativo, 0-Inativo
} Restaurante;

Restaurante lista[100];
int total = 0;

// ETAPA 2 - CADASTRAR
void cadastrar() {
    printf("Nome: "); fgets(lista[total].nome, 50, stdin);
    printf("Categoria: "); fgets(lista[total].categoria, 50, stdin);
    lista[total].estado = 0; // Inicia inativo
    total++;
}

// ETAPA 3 - LISTAR (Ciclo for)
void listar() {
    for(int i=0; i<total; i++)
        printf("%s | %s | %s\n", lista[i].nome, lista[i].categoria, lista[i].estado ? "Ativo" : "Inativo");
}

// ETAPA 4 e 5 - PESQUISAR / ALTERAR
void pesquisarAlterar(int mudar) {
    char busca[50];
    printf("Nome: "); fgets(busca, 50, stdin);
    for(int i=0; i<total; i++) {
        if(strcmp(lista[i].nome, busca) == 0) {
            if(mudar) lista[i].estado = !lista[i].estado;
            else printf("Existe: %s\n", lista[i].nome);
            return;
        }
    }
    printf("Erro: Não encontrado.\n");
}

// ETAPA 6 - MOSTRAR ATIVOS
void mostrarAtivos() {
    for(int i=0; i<total; i++)
        if(lista[i].estado == 1) printf("- %s\n", lista[i].nome);
}

// ETAPA 1 - MENU (Switch e Do While)
int main() {
    int op;
    do {
        printf("\n1-Add 2-List 3-Estado 4-Busca 5-Ativos 6-Sair: ");
        scanf("%d", &op); getchar();
        switch(op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: pesquisarAlterar(1); break;
            case 4: pesquisarAlterar(0); break;
            case 5: mostrarAtivos(); break;
        }
    } while(op != 6);
    return 0;
}
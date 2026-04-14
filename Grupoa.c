#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Necessário para o system("cls" ou "clear")

#define MAX 100

typedef struct {
    char nome[50];
    char categoria[50];
    int estado; // 1-Ativo, 0-Inativo
} Restaurante;

Restaurante lista[MAX];
int total = 0;

// Função auxiliar para limpar o buffer e remover o '\n' do fgets
void limparTexto(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void cadastrar() {
    if (total >= MAX) {
        printf("\n[ERRO] Limite de armazenamento atingido!\n");
        return;
    }

    printf("\n--- CADASTRAR RESTAURANTE ---\n");
    printf("Nome: ");
    fgets(lista[total].nome, 50, stdin);
    limparTexto(lista[total].nome);

    printf("Categoria: ");
    fgets(lista[total].categoria, 50, stdin);
    limparTexto(lista[total].categoria);

    lista[total].estado = 0; 
    total++;
    printf("\n>> Cadastrado com sucesso!\n");
}

void listar() {
    printf("\n--- LISTA DE RESTAURANTES ---\n");
    if (total == 0) printf("Nenhum restaurante cadastrado.\n");
    
    for(int i = 0; i < total; i++) {
        printf("%-20s | %-15s | %s\n", 
               lista[i].nome, 
               lista[i].categoria, 
               lista[i].estado ? "[Ativo]" : "[Inativo]");
    }
}

void pesquisarAlterar(int mudarEstado) {
    char busca[50];
    printf("\nDigite o nome para %s: ", mudarEstado ? "alterar estado" : "buscar");
    fgets(busca, 50, stdin);
    limparTexto(busca);

    for(int i = 0; i < total; i++) {
        if(strcmp(lista[i].nome, busca) == 0) {
            if(mudarEstado) {
                lista[i].estado = !lista[i].estado;
                printf("\n>> Estado de '%s' alterado para: %s\n", 
                        lista[i].nome, lista[i].estado ? "Ativo" : "Inativo");
            } else {
                printf("\nEncontrado: %s (%s) - %s\n", 
                        lista[i].nome, lista[i].categoria, lista[i].estado ? "Ativo" : "Inativo");
            }
            return;
        }
    }
    printf("\n[ERRO] Restaurante '%s' não encontrado.\n", busca);
}

void mostrarAtivos() {
    printf("\n--- RESTAURANTES ATIVOS ---\n");
    int encontrou = 0;
    for(int i = 0; i < total; i++) {
        if(lista[i].estado == 1) {
            printf("- %s (%s)\n", lista[i].nome, lista[i].categoria);
            encontrou = 1;
        }
    }
    if(!encontrou) printf("Não há restaurantes ativos no momento.\n");
}

int main() {
    int op;
    do {
        printf("\n==============================");
        printf("\n      GESTOR DE DELIVERY      ");
        printf("\n==============================");
        printf("\n1. Adicionar Restaurante");
        printf("\n2. Listar Todos");
        printf("\n3. Alternar Estado (On/Off)");
        printf("\n4. Pesquisar por Nome");
        printf("\n5. Ver Apenas Ativos");
        printf("\n0. Sair");
        printf("\n------------------------------");
        printf("\nOpcao: ");
        
        if (scanf("%d", &op) != 1) { // Validação simples de entrada
            while(getchar() != '\n'); 
            continue;
        }
        getchar(); // Limpa o buffer do enter

        switch(op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: pesquisarAlterar(1); break;
            case 4: pesquisarAlterar(0); break;
            case 5: mostrarAtivos(); break;
            case 0: printf("\nEncerrando sistema...\n"); break;
            default: printf("\n[!] Opcao invalida.\n");
        }
    } while(op != 0);

    return 0;
}
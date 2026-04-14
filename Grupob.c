#include <stdio.h>
#include <string.h>

#define MAX 100

// --- Estruturas de Dados ---
typedef struct {
    int id;
    char nome[50];
    int idade;
    char contacto[20];
} Paciente;

typedef struct {
    int idConsulta;
    int idPaciente;
    char data[11]; // DD/MM/AAAA
    char estado[20]; // Pendente, Realizada, Cancelada
} Consulta;

// --- Variáveis Globais (Arrays) ---
Paciente pacientes[MAX];
Consulta consultas[MAX];
int totalPacientes = 0;
int totalConsultas = 0;

// --- Funções Auxiliares ---
int procurarPaciente(int id) {
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i].id == id) return i;
    }
    return -1;
}

int temConsultas(int idPaciente) {
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].idPaciente == idPaciente) return 1;
    }
    return 0;
}

// --- Funcionalidades ---
void cadastrarPaciente() {
    if (totalPacientes >= MAX) {
        printf("Erro: Limite de pacientes atingido.\n");
        return;
    }
    printf("ID: "); scanf("%d", &pacientes[totalPacientes].id);
    printf("Nome: "); scanf(" %[^\n]", pacientes[totalPacientes].nome);
    printf("Idade: "); scanf("%d", &pacientes[totalPacientes].idade);
    printf("Contacto: "); scanf("%s", pacientes[totalPacientes].contacto);
    totalPacientes++;
    printf("Paciente cadastrado com sucesso!\n");
}

void marcarConsulta() {
    int idPac;
    printf("ID do Paciente: "); scanf("%d", &idPac);
    
    if (procurarPaciente(idPac) == -1) {
        printf("Erro: Paciente nao existe!\n");
        return;
    }

    consultas[totalConsultas].idConsulta = totalConsultas + 1;
    consultas[totalConsultas].idPaciente = idPac;
    printf("Data (DD/MM/AAAA): "); scanf("%s", consultas[totalConsultas].data);
    strcpy(consultas[totalConsultas].estado, "Pendente");
    totalConsultas++;
    printf("Consulta marcada!\n");
}

void listarPacientes() {
    printf("\n--- Lista de Pacientes ---\n");
    for (int i = 0; i < totalPacientes; i++) {
        printf("ID: %d | Nome: %s\n", pacientes[i].id, pacientes[i].nome);
    }
}

void eliminarPaciente() {
    int id, pos;
    printf("ID do paciente a eliminar: "); scanf("%d", &id);
    pos = procurarPaciente(id);

    if (pos == -1) {
        printf("Erro: Paciente nao encontrado.\n");
    } else if (temConsultas(id)) {
        printf("Erro: Nao pode eliminar paciente com consultas associadas!\n");
    } else {
        for (int i = pos; i < totalPacientes - 1; i++) {
            pacientes[i] = pacientes[i + 1];
        }
        totalPacientes--;
        printf("Paciente removido.\n");
    }
}

// --- Menu Principal ---
int main() {
    int opcao;

    do {
        printf("\n--- SISTEMA HOSPITALAR ---");
        printf("\n1. Cadastrar Paciente\n2. Listar Pacientes\n3. Marcar Consulta\n8. Eliminar Paciente\n9. Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarPaciente(); break;
            case 2: listarPacientes(); break;
            case 3: marcarConsulta(); break;
            case 8: eliminarPaciente(); break;
            case 9: printf("A sair...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 9);

    return 0;
}
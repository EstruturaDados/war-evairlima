#include <stdio.h>
#include <string.h>

// Criação da struct Territorio
// Essa estrutura armazena as informações de cada território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {

    // Vetor para armazenar 5 territórios
    struct Territorio territorios[5];

    int i;

    // Entrada de dados
    printf("=== CADASTRO DE TERRITORIOS ===\n\n");

    for(i = 0; i < 5; i++) {

        printf("Territorio %d\n", i + 1);

        // Leitura do nome do território
        printf("Digite o nome do territorio: ");
        scanf("%s", territorios[i].nome);

        // Leitura da cor do exército
        printf("Digite a cor do exercito: ");
        scanf("%s", territorios[i].cor);

        // Leitura da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Exibição dos dados cadastrados
    printf("\n=== TERRITORIOS CADASTRADOS ===\n\n");

    // Laço para mostrar os dados armazenados
    for(i = 0; i < 5; i++) {

        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);

        printf("-----------------------------\n");
    }

    return 0;
}
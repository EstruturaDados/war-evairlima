#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// =====================================
// STRUCT DO TERRITORIO
// =====================================
typedef struct {

    char nome[30];
    char cor[10];
    int tropas;

} Territorio;

// =====================================
// FUNCAO PARA CADASTRAR TERRITORIOS
// =====================================
void cadastrarTerritorios(Territorio *mapa, int quantidade) {

    int i;

    printf("\n=== CADASTRO DE TERRITORIOS ===\n\n");

    for(i = 0; i < quantidade; i++) {

        printf("Territorio %d\n", i + 1);

        printf("Nome do territorio: ");
        scanf("%s", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);

        printf("\n");
    }
}

// =====================================
// FUNCAO PARA EXIBIR TERRITORIOS
// =====================================
void exibirTerritorios(Territorio *mapa, int quantidade) {

    int i;

    printf("\n=== MAPA DE TERRITORIOS ===\n\n");

    for(i = 0; i < quantidade; i++) {

        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);

        printf("-----------------------------\n");
    }
}

// =====================================
// FUNCAO DE ATAQUE
// =====================================
void atacar(Territorio *atacante, Territorio *defensor) {

    int dadoAtacante;
    int dadoDefensor;

    // Sorteia numeros de 1 a 6
    dadoAtacante = rand() % 6 + 1;
    dadoDefensor = rand() % 6 + 1;

    printf("\n=== BATALHA ===\n");

    printf("%s atacou %s\n",
           atacante->nome,
           defensor->nome);

    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    // Verifica vencedor
    if(dadoAtacante > dadoDefensor) {

        printf("\nO atacante venceu!\n");

        // Territorio muda de dono
        strcpy(defensor->cor, atacante->cor);

        // Metade das tropas vai para o territorio conquistado
        defensor->tropas = atacante->tropas / 2;

        // Atacante perde metade das tropas
        atacante->tropas = atacante->tropas / 2;

    } else {

        printf("\nO defensor venceu!\n");

        // Atacante perde uma tropa
        atacante->tropas--;

        // Evita numero negativo
        if(atacante->tropas < 0) {

            atacante->tropas = 0;
        }
    }
}

// =====================================
// FUNCAO PARA LIBERAR MEMORIA
// =====================================
void liberarMemoria(Territorio *mapa) {

    free(mapa);

    printf("\nMemoria liberada com sucesso!\n");
}

// =====================================
// FUNCAO PRINCIPAL
// =====================================
int main() {

    int quantidade;
    int atacante;
    int defensor;
    int i;

    // Inicializa aleatoriedade
    srand(time(NULL));

    // Quantidade de territorios
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &quantidade);

    // Alocacao dinamica
    Territorio *mapa;

    mapa = (Territorio*) calloc(quantidade, sizeof(Territorio));

    // Verifica erro na memoria
    if(mapa == NULL) {

        printf("Erro ao alocar memoria!\n");

        return 1;
    }

    // Cadastro
    cadastrarTerritorios(mapa, quantidade);

    // Exibe mapa inicial
    exibirTerritorios(mapa, quantidade);

    // =====================================
    // SISTEMA DE ATAQUE
    // =====================================
    printf("\n=== SISTEMA DE ATAQUE ===\n");

    // Lista territorios
    for(i = 0; i < quantidade; i++) {

        printf("%d - %s (%s)\n",
               i,
               mapa[i].nome,
               mapa[i].cor);
    }

    // Escolha atacante
    printf("\nEscolha o territorio atacante: ");
    scanf("%d", &atacante);

    // Escolha defensor
    printf("Escolha o territorio defensor: ");
    scanf("%d", &defensor);

    // Validacao dos indices
    if(atacante < 0 || atacante >= quantidade ||
       defensor < 0 || defensor >= quantidade) {

        printf("\nIndice invalido!\n");

    }
    // Validacao de cores
    else if(strcmp(mapa[atacante].cor,
                   mapa[defensor].cor) == 0) {

        printf("\nNao e permitido atacar territorios da mesma cor!\n");

    }
    else {

        // Executa ataque usando ponteiros
        atacar(&mapa[atacante],
                &mapa[defensor]);

        // Exibe mapa atualizado
        exibirTerritorios(mapa, quantidade);
    }

    // Libera memoria
    liberarMemoria(mapa);

    return 0;
}
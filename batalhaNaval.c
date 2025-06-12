#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10

// Valor que representa a água no tabuleiro
#define AGUA 0

// Valor que representa um navio
#define NAVIO 3

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar um navio horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO) return 0; // Ultrapassa borda direita
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) return 0; // Sobreposição
    }
    return 1;
}

// Função para verificar se é possível posicionar um navio verticalmente
int podePosicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO) return 0; // Ultrapassa borda inferior
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar navio horizontalmente
void posicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para posicionar navio verticalmente
void posicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical

    // Verificar e posicionar navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linhaH, colunaH)) {
        posicionarHorizontal(tabuleiro, linhaH, colunaH);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Verificar e posicionar navio vertical
    if (podePosicionarVertical(tabuleiro, linhaV, colunaV)) {
        posicionarVertical(tabuleiro, linhaV, colunaV);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}

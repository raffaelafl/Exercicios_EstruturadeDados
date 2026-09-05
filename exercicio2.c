#include <stdio.h>
#include <stdlib.h>

struct lista {
    int linha;
    int coluna;
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct esparsa {
    int linhas;
    int colunas;
    struct lista* prim;
};
typedef struct esparsa Esparsa;

Esparsa* criar_matriz(int linhas, int colunas) {
    Esparsa* m = (Esparsa*) malloc(sizeof(Esparsa));

    m->linhas = linhas;
    m->colunas = colunas;
    m->prim = NULL;
    return m;
}

Lista* lst_insere(Lista* l, int linha, int coluna, int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->info = valor;
    novo->prox = l;
    return novo;
}

void imprimir_matriz(Esparsa* mat) {
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            Lista* l = mat->prim;
            int encontrado = 0;
            while (l != NULL) {
                if (l->linha == i && l->coluna == j) {
                    printf("%d ", l->info);
                    encontrado = 1;
                    break;
                }
                l = l->prox;
            }
            if (!encontrado)
                printf("0 ");
        }
        printf("\n");
    }
}

int consultar_elemento(Esparsa* mat, int linha, int coluna) {
    Lista* l = mat->prim;
    while (l != NULL) {
        if (l->linha == linha && l->coluna == coluna)
            return l->info;
        l = l->prox;
    }
    return 0;
}

int soma_linha(Esparsa* mat, int linha) {
    Lista* l = mat->prim;
    int soma = 0;
    while (l != NULL) {
        if (l->linha == linha)
            soma += l->info;
        l = l->prox;
    }
    return soma;
}

float percentual_nao_nulos(Esparsa* mat) {
    int total = mat->linhas * mat->colunas;
    int nao_nulos = 0;
    Lista* l = mat->prim;

    while (l != NULL) {
        nao_nulos++;
        l = l->prox;
    }

    return ((float)nao_nulos / total) * 100.0;
}

int main() {
    int linhas, colunas;
    int op;
    Esparsa* matriz;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    matriz = criar_matriz(linhas, colunas);

    do {
        printf("\n\nMenu\n");
        printf("1) Inserir valor nao nulo\n");
        printf("2) Imprimir matriz\n");
        printf("3) Consultar valor\n");
        printf("4) Somar linha\n");
        printf("5) Percentual de nao nulos\n");
        printf("0) Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 1) {
            int lin, col, valor;
            printf("Linha, Coluna, Valor: ");
            scanf("%d %d %d", &lin, &col, &valor);

            if (lin >= 0 && lin < matriz->linhas &&
                col >= 0 && col < matriz->colunas &&
                valor != 0) {

                Lista *aux = matriz->prim;
                int existe = 0;

                while (aux != NULL) {
                    if (aux->linha == lin && aux->coluna == col) {
                        aux->info = valor;
                        existe = 1;
                        break;
                    }
                    aux = aux->prox;
                }

                if (!existe)
                    matriz->prim = lst_insere(matriz->prim, lin, col, valor);
            } else {
                printf("Posicao ou valor invalido");
            }
        }
        else if (op == 2) {
            imprimir_matriz(matriz);
        }
        else if (op == 3) {
            int lin, col, valor;
            printf("Linha e coluna para consultar: ");
            scanf("%d %d", &lin, &col);
            valor = consultar_elemento(matriz, lin, col);
            printf("Valor encontrado: %d\n", valor);
        }
        else if (op == 4) {
            int lin, soma;
            printf("Linha para somar: ");
            scanf("%d", &lin);
            soma = soma_linha(matriz, lin);
            printf("Soma: %d\n", soma);
        }
        else if (op == 5) {
            printf("Percentual de elementos nao nulos: %.2f%%\n", percentual_nao_nulos(matriz));
        }

    } while (op != 0);

    return 0;
}

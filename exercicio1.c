#include <stdio.h>
#include <stdlib.h>

struct diagonal {
    int ordem;
    int* v;
};
typedef struct diagonal Diagonal;

Diagonal* criarMatriz(int ordem) {
    Diagonal* p = (Diagonal*)malloc(sizeof(Diagonal));
    p->ordem = ordem;
    p->v = (int*)malloc(ordem * sizeof(int));
    return p;
}

void preencherMatriz(Diagonal* p) {
    printf("Digite os %d elementos da diagonal principal:\n", p->ordem);
    for (int i = 0; i < p->ordem; i++) {
        printf("Elemento [%d][%d]: ", i, i);
        scanf("%d", &p->v[i]);
    }
}

void imprimirMatriz(Diagonal* p) {
    printf("\n>Matriz diagonal:\n");
    for (int i = 0; i < p->ordem; i++) {
        for (int j = 0; j < p->ordem; j++) {
            if (i == j) {
                printf("%d ", p->v[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void consultarElemento(Diagonal* p, int linha, int coluna) {
    if (linha < 0 || linha >= p->ordem || coluna < 0 || coluna >= p->ordem) {
        printf("Posição invalida.\n");
        return;
    }
    if (linha == coluna) {
        printf("Elemento [%d][%d] = %d \n", linha, coluna, p->v[linha]);
    } else {
        printf("Elemento [%d][%d] = 0\n", linha, coluna);
    }
}

void liberarMatriz(Diagonal* d) {
    free(d->v);
    free(d);
}

int main() {
    int ordem, linha, coluna;

    printf(">Qual a ordem da matriz diagonal? ");
    scanf("%d", &ordem);
    Diagonal* matriz = criarMatriz(ordem);

    preencherMatriz(matriz);
    imprimirMatriz(matriz);

    printf("\n>Consulta de elemento\nDigite linha e coluna:\n");
    scanf("%d %d", &linha, &coluna);
    consultarElemento(matriz, linha, coluna);
    liberarMatriz(matriz);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int*** aloca_matriz(int l, int c, int p);
void preenche_matriz(int l, int c, int p, int ***mat);
void imprime_matriz(int l, int c, int p, int ***mat);

int*** aloca_matriz(int l, int c, int p) {
    int ***mat = malloc(l * sizeof(int**));
    if (!mat) {
        printf("Erro ao alocar matriz\n");
        exit(1);
    }

    for (int i = 0; i < l; i++) {
        mat[i] = malloc(c * sizeof(int*));
        if (!mat[i]) {
            printf("Erro ao alocar matriz\n", i);
            exit(1);
        }
        for (int j = 0; j < c; j++) {
            mat[i][j] = malloc(p * sizeof(int));
            if (!mat[i][j]) {
                printf("Erro ao alocar matriz\n", i, j);
                exit(1);
            }
        }
    }
    return mat;
}

void preenche_matriz(int l, int c, int p, int ***mat) {
    printf("Preencha os valores:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < p; k++) {
                printf("mat[%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

void imprime_matriz(int l, int c, int p, int ***mat) {
    printf("\nMatriz 3D:\n");
    for (int i = 0; i < l; i++) {
        printf("Camada %d:\n", i);
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < p; k++) {
                printf("%d ", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


int main() {
    int l, c, p;

    printf("Digite o numero de linhas: ");
    scanf("%d", &l);
    printf("Digite o nimero de colunas: ");
    scanf("%d", &c);
    printf("Digite a profundidade: ");
    scanf("%d", &p);

    int ***mat = aloca_matriz(l, c, p);
    preenche_matriz(l, c, p, mat);
    imprime_matriz(l, c, p, mat);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);

    return 0;
}

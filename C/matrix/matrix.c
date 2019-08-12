#include <stdio.h>
#include "matrix.h"

/* 行列を初期化する */
void init_matrix(Matrix* entry) {
    entry->row = 3;
    entry->col = 3;

    for (int i = 0; i < entry->row; i = i + 1) {
        for (int j = 0; j < entry->col; j = j + 1) {
            entry->data[i][j] = 0;
        }
    }
}

/* 行列を表示する */
void print_matrix(Matrix* entry) {
    for (int i = 0; i < entry->row; i = i + 1) {
        for (int j = 0; j < entry->col; j = j + 1) {
            printf("%d ", entry->data[i][j]);
        }
        printf("\n");
    }
    /* 行列の終わりであることを示すため空行を入れる */
    printf("\n");
}

/* 行列の加算 */

void add_matrix(Matrix* mat1, Matrix* mat2) {
    for (int i = 0; i < mat1->row; i = i + 1) {
        for (int j = 0; j < mat1->col; j = j + 1) {
            mat1->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
}

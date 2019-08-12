#ifndef LEARNC_MATRIX_H
#define LEARNC_MATRIX_H // マクロ
struct matrix {
    int row;         /* 行方向の要素数。現在は3に固定 */
    int col;         /* 列方向（column）の要素数。現在は3に固定 */
    int data[3][3];  /* 行列の各要素 */
};

typedef struct matrix Matrix;

/* 行列を初期化する */
void init_matrix(Matrix* entry);

/* 行列を表示する */
void print_matrix(Matrix* entry);

/* 行列の加算 */
void add_matrix(Matrix* mat1, Matrix* mat2);

#endif //LEARNC_MATRIX_H

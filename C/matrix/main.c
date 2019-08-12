#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix mat1, mat2;

    /* 初期化 */
    init_matrix(&mat1);
    init_matrix(&mat2);

    /* 対角成分に1を入れて単位行列にする */
    mat1.data[0][0] = 1;
    mat1.data[1][1] = 1;
    mat1.data[2][2] = 1;

    /* 1行目のすべての要素に5を入れる */
    mat2.data[0][0] = 5;
    mat2.data[0][1] = 5;
    mat2.data[0][2] = 5;

    /* 表示 */
    print_matrix(&mat1);
    printf("  +  \n\n");
    print_matrix(&mat2);

    /* 加算 */
    add_matrix(&mat1, &mat2);

    /* 表示 */
    printf("  =  \n\n");
    print_matrix(&mat1);

    return 0;
}
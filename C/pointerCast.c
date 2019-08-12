#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;

    printf("要素数を入力してください\n");
    scanf("%d", &number);

    printf("%d個の要素をもつ配列相当の領域を確保\n", number);

    /* int 型で number 個分の領域を確保 */
    /* (int*)でintのポインタ型にキャスト */
    int* array = (int*)malloc(sizeof(int) * number);

    array[0] = 1;
    for (int i = 1; i < number; i = i + 1) {
        array[i] = array[i - 1] * 2
    }

    /* 要素末尾からprintf */
    for (int i = number - 1; i >= 0; i = i - 1) {
        printf("%d\n", array[i]);
    }

    /* 使わなくなった領域を解放 */
    free(array);

    return 0;
}

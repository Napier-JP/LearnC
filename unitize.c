#include <stdio.h>
#include <math.h>

// &a は aという変数のメモリアドレス
// *b は bというメモリアドレスのところにある実体
void unitize(float* x, float* y) {
    float vecX = *x;
    float vecY = *y;
    float length = sqrtf(vecX*vecX+vecY*vecY);

    *x = vecX / length;
    *y = vecY / length;
}

int main() {
    float x = 96.74;
    float y = 64.51;

    printf("(%f, %f)\n", x, y);

    unitize(&x, &y);

    printf("(%f, %f)\n", x, y);

    return 0;
}

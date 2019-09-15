// g++ -std=c++11 -Ofast -fopenmp matrix_product.cpp
#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

int main() {
    int A[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int B[3][3] = {{3, 2, 1},
                   {6, 5, 4},
                   {9, 8, 7}};
    int C1[3][3] = {};  // ゼロ初期化 C99では{0}
    int N = sizeof(A) / sizeof(A[0]);


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C1[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "======Sequential======" << "\n";
    for (const auto& row : C1) { // auto&は参照（鏡像コピー）　アドレス演算子ではない
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }


    // A, Bは読み出されるだけであり、また処理にデータ依存性はない（前の計算結果は使われない）
    // Cの要素への加算は排他的に行う必要がある
    // Cの一行ごとに最外ループiは回り、当該行の各要素jについて「kループで加算」が入る
    // つまりi, jはめいめい分担してやらせても問題がない（kループは一つのスレッドが単独で責任をもって全部担当する）
    // だが今回はiだけを並列化し、j, kは同一のスレッドが最初から最後まで担当する
    int C2[3][3] = {};
#pragma omp parallel for  // j, kがiループ内で宣言されるのでprivateにする必要がない
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C2[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "======Parallel======" << "\n";
    for (const auto& row : C2) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }


    cout << "======END======" << "\n";
    return 0;
}

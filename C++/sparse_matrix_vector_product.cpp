#include <bits/stdc++.h>

using namespace std;

int main() {
    int denseA[4][4] = {{0, 0, 0, 0},
                        {0, 0, 0, 5},
                        {1, 3, 0, 0},
                        {0, 0, 0, 0}};
    int x[4][1] = {{3},
                   {1},
                   {4},
                   {2}};

    cout << "=====Sequential Dense=====" << "\n";
    int y_sd[4][1] = {};

    for (int i = 0; i < sizeof(y_sd) / sizeof(y_sd[0]); ++i) {  // y_sdの各行
        for (int j = 0; j < sizeof(y_sd[0]) / sizeof(y_sd[0][0]); ++j) {  // y_sdの各列(1つだけ)
            for (int k = 0; k < sizeof(x) / sizeof(x[0]); ++k) {  // Aの各列・xの各行
                y_sd[i][j] += denseA[i][k] * x[k][j];
            }
        }
    }
    for (const auto& row : y_sd) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }

    cout << "=====Sequential Sparse CRS/CSR=====" << "\n";
    vector<int> A_rowIndicesOfNonZeroElements{1, 3, 3};  // 素朴な出現行インデックス配列
    vector<int> A_eachRowFirstElementIdxInValues{0, 0, 1, 3, 3};  // [i]はi行目に初めて出現するnon-zero要素の、値配列におけるインデックス（ただし次の行も同じ値なら、i行目が空行であることを意味する）末尾の3は最下行が空行かどうか検出するためのもの
    vector<int> A_colIndicesOfNonZeroElements{3, 0, 1};
    vector<int> A_values{5, 1, 3};
    vector<vector<int>> y_ss_crs(4, vector<int>(1, 0));

    for (int rowIdx = 0; rowIdx < y_ss_crs.size(); ++rowIdx) {  // y_ss_crsの各行
        for (int colIdx = 0; colIdx < y_ss_crs[0].size(); ++colIdx) {  // y_ss_crsの各列(1つだけ)
            int elementsInThisRowCount = A_eachRowFirstElementIdxInValues[rowIdx + 1] - A_eachRowFirstElementIdxInValues[rowIdx];

            for (int idxInThisRow = 0; idxInThisRow < elementsInThisRowCount; ++idxInThisRow) {  // y_ss_crsの当該行のうち、non-zero要素の個数分だけ（不定）
                int idxInValues = A_eachRowFirstElementIdxInValues[rowIdx] + idxInThisRow;
                y_ss_crs[rowIdx][colIdx] += A_values[idxInValues] * x[A_colIndicesOfNonZeroElements[idxInValues]][colIdx];
            }
        }
    }
    for (const auto& row : y_ss_crs) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }

    cout << "=====END=====\n";
    return 0;
}

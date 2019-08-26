#include <bits/stdc++.h>
#include <omp.h>

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8};
    int dotProduct = 0; // 1 + 4 + 9 + 16 + 25 + 36 + 49 + 64 = 204
    
    // sequential
    std::cout << "===sequential===" << "\n";
    for (int i = 0; i < 8; ++i) {
        dotProduct += a[i] * b[i];
    }
    std::cout << dotProduct << "\n";
    dotProduct = 0;

    // parallel w/o reduction
    std::cout << "===parallel with no reduction===" << "\n";
#pragma omp parallel for
    for (int i = 0; i < 8; ++i) {
        dotProduct += a[i] * b[i];
        printf("adding: %d, dotProduct is now: %d\n", a[i] * b[i], dotProduct);
    }
    std::cout << dotProduct << "\n";
    dotProduct = 0;

    // parallel w/ reduction
    std::cout << "===parallel with reduction===" << "\n";
#pragma omp parallel for reduction (+: dotProduct)
    for (int i = 0; i < 8; ++i) {
        dotProduct += a[i] * b[i];
    }
    std::cout << dotProduct << "\n";

    std::cout << "===END===" << "\n";
    return 0;
}

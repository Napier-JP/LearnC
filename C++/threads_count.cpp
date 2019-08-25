#include <bits/stdc++.h>
#include <omp.h>

int main() {
    std::vector<char> alphabets(26);
    char c = 'A';
    for (int i = 0; i < 26; ++i) {
        alphabets[i] = c;
        ++c;
    }
#pragma omp parallel for
    for (int i = 0; i < 20; ++i) {
        printf("%c %d / %d\n", alphabets[i], omp_get_thread_num(), omp_get_max_threads());
    }

    return 0;
}

/* Output on WSL Ubuntu w/ i7-6700 (4C8T) was:
M 4 / 8
N 4 / 8
S 7 / 8
T 7 / 8
D 1 / 8
E 1 / 8
F 1 / 8
G 2 / 8
H 2 / 8
I 2 / 8
A 0 / 8
B 0 / 8
C 0 / 8
J 3 / 8
K 3 / 8
L 3 / 8
Q 6 / 8
R 6 / 8
O 5 / 8
P 5 / 8
*/

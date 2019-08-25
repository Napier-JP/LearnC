#include <bits/stdc++.h>
#include <omp.h>

int main() {
    #pragma omp parallel for
    for (int i = 0; i < 20; ++i) {
        printf("%d / %d\n", omp_get_thread_num(), omp_get_max_threads());
    }

    return 0;
}

/* Output on WSL Ubuntu w/ i7-6700 (4C8T) was:
0 / 8
0 / 8
0 / 8
4 / 8
4 / 8
3 / 8
3 / 8
3 / 8
2 / 8
2 / 8
2 / 8
5 / 8
5 / 8
7 / 8
7 / 8
6 / 8
6 / 8
1 / 8
1 / 8
1 / 8
*/

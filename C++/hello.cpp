#include <iostream>
#include <math.h>
namespace altName = std;
using std::endl;

int main() {
    altName::cout << "Hello" << std::endl << "World!" << endl;
    std::cout << 3.1415 << altName::endl; // usingしているのでendl単体でもok
    int input;
    scanf("%d", &input); // iostreamの中にscanfがある？勝手に探している？
    std::printf("%.2f\n", sqrt(input)); // math.hがあるのでstd::なしでsqrtを呼べる
    return 0;
}

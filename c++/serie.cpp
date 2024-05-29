#include <iostream>
#include <cmath>

int main() {
    double sum = 0;
    for (int i = 1; i <= 99; i++) {
        sum += pow(3, i) / (100 - i);
        if (i % 2 == 0) {
            sum *= -1;
        }
    }
    std::cout << "Resultado da soma: " << sum << std::endl;
    return 0;
}
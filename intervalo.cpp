#include <iostream>

int main() {
    int m, n;
    std::cout << "Digite o valor de m: ";
    std::cin >> m;
    std::cout << "Digite o valor de n: ";
    std::cin >> n;

    int sum = 0;
    for (int i = n; i <= m; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }
    std::cout << "A soma de todos os números ímpares entre " << n << " e " << m << " é: " << sum << std::endl;
    return 0;
}
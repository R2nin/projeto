#include <iostream>

int main() {
    int M;
    std::cout << "Digite a quantidade de pessoas: ";
    std::cin >> M;

    int idade;
    int somaIdades = 0;

    for (int i = 0; i < M; i++) {
        std::cout << "Digite a idade da pessoa " << i + 1 << ": ";
        std::cin >> idade;
        somaIdades += idade;
    }

    double media = static_cast<double>(somaIdades) / M;
    std::cout << "A média de idade deste grupo é: " << media << std::endl;

    return 0;
}
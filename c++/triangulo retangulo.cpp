#include <iostream>
#include <locale.h>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Portuguese");
    double base, height;
    std::cout << "Digite a base do triangulo: ";
    std::cin >> base;
    while (base <= 0) {
        std::cout << "A base deve ser maior que 0. Digite novamente: ";
        std::cin >> base;
    }
    std::cout << "Digite a altura do triangulo: ";
    std::cin >> height;
    while (height <= 0) {
        std::cout << "A altura deve ser maior que 0. Digite novamente: ";
        std::cin >> height;
    }
    double area = 0.5 * base * height;
    std::cout << "A area do triangulo e: " << area << std::endl;
    return 0;
}

#include <iostream>

const int SIZE = 6;

int main() {
    int valor[SIZE][SIZE];
    int resultado[SIZE] = {0}; // Inicializa o vetor resultado com zeros

    // Ler os valores da matriz VALOR
    std::cout << "Digite os valores da matriz VALOR 6x6:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> valor[i][j];
        }
    }

    // Calcular a soma de cada linha e armazenar no vetor RESULTADO
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            resultado[i] += valor[i][j];
        }
    }

    // Exibir o vetor RESULTADO
    std::cout << "Vetor RESULTADO:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Soma da linha " << i + 1 << ": " << resultado[i] << "\n";
    }

    return 0;
}
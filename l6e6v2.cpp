#include <iostream>

const int SIZE = 5;

int main() {
    int matrix[SIZE][SIZE];

    // Ler os valores da matriz
    std::cout << "Digite os valores da matriz P 5x5:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Verificar se a matriz é simétrica
    bool isSymmetric = true;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    // Exibir o resultado
    if (isSymmetric) {
        std::cout << "A matriz e simetrica.\n";
    } else {
        std::cout << "A matriz nao e simetrica.\n";
    }

    return 0;
}
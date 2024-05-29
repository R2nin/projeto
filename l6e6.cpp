#include <iostream>

const int SIZE = 5;

bool isSymmetric(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

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
    if (isSymmetric(matrix)) {
        std::cout << "A matriz é simétrica.\n";
    } else {
        std::cout << "A matriz não é simétrica.\n";
    }

    return 0;
}
#include <iostream>

int main() {
    int matriz[2][3];
    int i = 0, j = 0;

    while (j < 3) {
        while (i < 2) {
            std::cout << "Digite o elemento da matriz[" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
            i++;
        }
        i = 0;
        j++;
    }

    std::cout << "Matriz lida:" << std::endl;

    i = 0;
    while (i < 2) {
        j = 0;
        while (j < 3) {
            std::cout << matriz[i][j] << " ";
            j++;
        }
        std::cout << std::endl;
        i++;
    }

    return 0;
}

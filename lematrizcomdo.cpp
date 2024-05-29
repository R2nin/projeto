#include <iostream>

int main() {
    int matriz[2][3];
    int i = 0, j = 0;

    do {
        do {
            std::cout << "Digite o elemento da matriz[" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
            j++;
        } while (j < 3);
        j = 0;
        i++;
    } while (i < 2);

    std::cout << "Matriz lida:" << std::endl;

    i = 0;
    do {
        j = 0;
        do {
            std::cout << matriz[i][j] << " ";
            j++;
        } while (j < 3);
        std::cout << std::endl;
        i++;
    } while (i < 2);

    return 0;
}

#include <iostream>
int main() {
    int matriz[2][3];
    int i = 0, j = 0;
    for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
    {
       std::cin >> matriz[i][j];
    }
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
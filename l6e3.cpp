#include <iostream>
using namespace std;

int main() {
    // Definir a matriz A[5x4]
    int A[5][4];

    // Ler os valores da matriz A
    cout << "Digite os valores da matriz A[5x4]:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> A[i][j];
        }
    }

    // Gerar a matriz transposta TrA
    int TrA[4][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            TrA[j][i] = A[i][j];
        }
    }

    // Imprimir a matriz transposta TrA
    cout << "Matriz transposta TrA:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << TrA[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
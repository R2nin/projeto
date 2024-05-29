#include <iostream>
using namespace std;

int main() {
    // Definir a matriz A[3x6]
    int A[3][6];

    // Ler os valores da matriz A
    cout << "Digite os valores da matriz A[3x6]:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> A[i][j];
        }
    }

    // Calcular a média das colunas e armazenar os resultados no vetor soma
    int soma[6] = {0}; // Inicializar o vetor soma com zeros

    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 3; i++) {
            soma[j] += A[i][j];
        }
        soma[j] /= 3;
    }

    // Imprimir os resultados
    cout << "Média das colunas:\n";
    for (int j = 0; j < 6; j++) {
        cout << "Coluna " << j+1 << ": " << soma[j] << endl;
    }

    return 0;
}
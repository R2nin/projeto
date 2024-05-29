#include <iostream>
using namespace std;

int main() {
    int A[6];
    int B[6];

    // Lendo os elementos do vetor A
    cout << "Digite 6 números inteiros para o vetor A:" << endl;
    for (int i = 0; i < 6; i++) {
        cin >> A[i];
    }

    // Construindo o vetor B a partir dos elementos do vetor A divididos por 4
    for (int i = 0; i < 6; i++) {
        B[i] = A[i] / 4;
    }

    // Exibindo o vetor B
    cout << "Vetor B (elementos de A divididos por 4):" << endl;
    for (int i = 0; i < 6; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}

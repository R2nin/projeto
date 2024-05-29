#include <iostream>
using namespace std;

int main() {
    int A[15];
    int B[15];
    int C[30];

    // Lendo os elementos do vetor A
    cout << "Digite 15 números inteiros para o vetor A:" << endl;
    for (int i = 0; i < 15; i++) {
        cin >> A[i];
    }

    // Lendo os elementos do vetor B
    cout << "Digite 15 números inteiros para o vetor B:" << endl;
    for (int i = 0; i < 15; i++) {
        cin >> B[i];
    }

    // Construindo o vetor C com a junção dos elementos de A e B
    for (int i = 0; i < 15; i++) {
        C[i] = A[i];
        C[i + 15] = B[i];
    }

    // Exibindo o vetor C
    cout << "Vetor C (junção dos elementos de A e B):" << endl;
    for (int i = 0; i < 30; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}

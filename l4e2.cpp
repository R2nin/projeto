#include <iostream>
using namespace std;

int main() {
    int A[20];
    int B[20];
    int C[20];

    // Lendo os elementos dos vetores A e B
    cout << "Digite 20 números inteiros para o vetor A:" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> A[i];
    }

    cout << "Digite 20 números inteiros para o vetor B:" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> B[i];
    }

    // Construindo o vetor C
    for (int i = 0; i < 20; i++) {
        C[i] = A[i] + B[i];
    }

    // Exibindo o vetor C
    cout << "Vetor C (adição dos elementos de A e B):" << endl;
    for (int i = 0; i < 20; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}

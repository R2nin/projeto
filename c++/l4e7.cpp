#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vetor(40);
    unordered_map<int, int> contador;

    // Lendo a lista de 10 números inteiros e armazenando no vetor
    cout << "Digite 10 números inteiros não repetidos:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> vetor[i];
    }

    // Lendo a lista de números e verificando se cada número está no vetor
    cout << "Digite uma lista de números (terminada por 0):" << endl;
    int numero;
    do {
        cin >> numero;
        if (numero != 0) {
            // Verificando se o número está no vetor
            auto it = find(vetor.begin(), vetor.end(), numero);
            if (it != vetor.end()) {
                // Incrementando o contador para o número encontrado
                contador[numero]++;
            }
        }
    } while (numero != 0);

    // Mostrando o número de vezes que cada número do vetor foi encontrado
    cout << "Número de vezes que cada número foi encontrado:" << endl;
    for (int i = 0; i < 10; i++) {
        int numero = vetor[i];
        int vezesEncontrado = contador[numero];
        cout << "Número " << numero << ": " << vezesEncontrado << " vezes" << endl;
    }

    return 0;
}

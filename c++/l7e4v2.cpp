#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    vector<int> vetor(40);
    unordered_map<int, int> contador;

    // Populando o vetor com números inteiros aleatórios
    srand(time(NULL)); // Semente para geração de números aleatórios baseada no tempo atual
    for (int i = 0; i < 40; i++) {
        vetor[i] = rand();
        cout << vetor[i] << " ";
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
    for (int i = 0; i < 40; i++) {
        int numero = vetor[i];
        int vezesEncontrado = contador[numero];
        cout << "Número " << numero << ": " << vezesEncontrado << " vezes" << endl;
    }

    return 0;
}

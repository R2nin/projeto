#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> SENADOR = {"Senador1", "Senador2", "Senador3", "Senador4", "Senador5", "Senador6", "Senador7", "Senador8", "Senador9", "Senador10", "Senador11", "Senador12", "Senador13", "Senador14", "Senador15", "Senador16", "Senador17", "Senador18", "Senador19", "Senador20"};
    vector<int> SINDICANCIA = {5, 8, 12, 3, 15, 7, 0, 11, 4, 2, 9, 6, 1, 14, 10, 13, 17, 16, 19, 18};

    // Imprimir nome e quantidade de investigações para cada Senador investigado menos de 10 vezes
    int senadoresImpressos = 0;
    cout << "Senadores investigados menos de 10 vezes:" << endl;
    for (int i = 0; i < SENADOR.size(); i++) {
        if (SINDICANCIA[i] < 10) {
            cout << SENADOR[i] << ": " << SINDICANCIA[i] << " investigações" << endl;
            senadoresImpressos++;
        }
    }
    cout << "Quantidade de Senadores impressos: " << senadoresImpressos << endl;

    // Classificar o vetor SINDICANCIA em ordem crescente
    sort(SINDICANCIA.begin(), SINDICANCIA.end());

    // Classificar o vetor SINDICANCIA em ordem decrescente
    sort(SINDICANCIA.rbegin(), SINDICANCIA.rend());

    return 0;
}

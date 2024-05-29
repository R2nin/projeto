#include <iostream>
#include <limits>
using namespace std;

int main() {
    double vetor[20];
    double maiorValor = -numeric_limits<double>::infinity();
    double menorValor = numeric_limits<double>::infinity();
    int posicaoMaiorValor, posicaoMenorValor;
    double soma = 0;

    // Lendo os elementos do vetor
    cout << "Digite 20 valores reais para o vetor:" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> vetor[i];
        soma += vetor[i];

        if (vetor[i] > maiorValor) {
            maiorValor = vetor[i];
            posicaoMaiorValor = i;
        }

        if (vetor[i] < menorValor) {
            menorValor = vetor[i];
            posicaoMenorValor = i;
        }
    }

    // Calculando a média dos elementos do vetor
    double media = soma / 20;

    // Exibindo a posição do maior e menor valor, e a soma e média dos elementos do vetor
    cout << "Maior valor: " << maiorValor << ", posição: " << posicaoMaiorValor << endl;
    cout << "Menor valor: " << menorValor << ", posição: " << posicaoMenorValor << endl;
    cout << "Soma dos elementos: " << soma << endl;
    cout << "Média dos elementos: " << media << endl;

    return 0;
}

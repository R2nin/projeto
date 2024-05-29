#include <iostream>
#include <vector>
#include <string>
int main() {
    std::vector<std::string> nomes;
    std::vector<int> notas;

    // Ler o nome e a nota de 10 alunos
    for (int i = 0; i < 10; i++) {
        std::string nome;
        int nota;

        std::cout << "Digite o nome do aluno " << i+1 << ": ";
        std::cin >> nome;

        std::cout << "Digite a nota do aluno " << i+1 << ": ";
        std::cin >> nota;

        nomes.push_back(nome);
        notas.push_back(nota);
    }

    // Procurar a maior nota no vetor de notas
    int maiorNota = notas[0];
    int indiceMaiorNota = 0;

    for (int i = 1; i < 10; i++) {
        if (notas[i] > maiorNota) {
            maiorNota = notas[i];
            indiceMaiorNota = i;
        }
    }

    // Mostrar o nome do aluno com a maior nota
    std::cout << "Aluno com a maior nota: " << nomes[indiceMaiorNota] << std::endl;

    return 0;
}

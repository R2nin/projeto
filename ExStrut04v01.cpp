#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    float nota1;
    float nota2;
};

int main() {
    const int NUM_ALUNOS = 3;
    Aluno alunos[NUM_ALUNOS];

    // Leitura dos dados dos alunos
    for (int i = 0; i < NUM_ALUNOS; i++) {
        cout << "Digite o nome do aluno " << i+1 << ": ";
        getline(cin, alunos[i].nome);

        cout << "Digite a nota 1 do aluno " << i+1 << ": ";
        cin >> alunos[i].nota1;

        cout << "Digite a nota 2 do aluno " << i+1 << ": ";
        cin >> alunos[i].nota2;

        cin.ignore(); // Limpa o buffer do teclado
        cout << endl;
    }

    // Cálculo das médias dos alunos e da sala
    float mediaSala = 0;
    float menorMedia = 10;
    string nomesMenorMedia = "";

    for (int i = 0; i < NUM_ALUNOS; i++) {
        float mediaAluno = (alunos[i].nota1 + alunos[i].nota2) / 2;
        mediaSala += mediaAluno;

        cout << "Aluno " << i+1 << ": " << alunos[i].nome << endl;
        cout << "Media: " << mediaAluno << endl << endl;

        if (mediaAluno < menorMedia) {
            menorMedia = mediaAluno;
            nomesMenorMedia = alunos[i].nome;
        } else if (mediaAluno == menorMedia) {
            nomesMenorMedia += ", " + alunos[i].nome;
        }
    }

    mediaSala /= NUM_ALUNOS;

    // Exibição da menor média e dos respectivos nomes dos alunos
    cout << "Menor media: " << menorMedia << endl;
    cout << "Aluno(s): " << nomesMenorMedia << endl << endl;

    // Exibição da média da sala
    cout << "Media da sala: " << mediaSala << endl;

    return 0;
}

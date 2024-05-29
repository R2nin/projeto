#include <iostream>
#include <string>

struct Aluno {
    std::string nome;
    double nota1;
    double nota2;
};

int main() {
    Aluno alunos[3];

    // Leitura dos dados de três alunos
    for (int i = 0; i < 3; i++) {
        std::cout << "Aluno " << i + 1 << std::endl;
        std::cout << "Nome: ";
        std::cin >> alunos[i].nome;
        std::cout << "Nota 1: ";
        std::cin >> alunos[i].nota1;
        std::cout << "Nota 2: ";
        std::cin >> alunos[i].nota2;
        std::cout << std::endl;
    }

    double mediaSala = 0;
    double menorMedia = 10;
    std::string alunosMenorMedia;

    // Cálculo da média das notas de cada aluno
    for (int i = 0; i < 3; i++) {
        double mediaAluno = (alunos[i].nota1 + alunos[i].nota2) / 2;
        std::cout << "Aluno: " << alunos[i].nome << std::endl;
        std::cout << "Media: " << mediaAluno << std::endl;
        std::cout << std::endl;

        mediaSala += mediaAluno;

        if (mediaAluno < menorMedia) {
            menorMedia = mediaAluno;
            alunosMenorMedia = alunos[i].nome;
        } else if (mediaAluno == menorMedia) {
            alunosMenorMedia += ", " + alunos[i].nome;
        }
    }

    // Cálculo da média da sala
    mediaSala /= 3;

    std::cout << "Media da sala: " << mediaSala << std::endl;
    std::cout << "Menor media: " << menorMedia << " (Aluno(s): " << alunosMenorMedia << ")" << std::endl;

    return 0;
}
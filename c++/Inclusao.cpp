#include <iostream>
#include <fstream>
#include <string>

struct Registro {
    int id;
    std::string nome;
    std::string email;
};

void incluirRegistro(Registro novoRegistro) {
    std::ofstream arquivoTransacoes("transacoes.txt", std::ios::app);
    if (arquivoTransacoes.is_open()) {
        arquivoTransacoes << novoRegistro.id << " " << novoRegistro.nome << " " << novoRegistro.email << std::endl;
        arquivoTransacoes.close();
        std::cout << "Registro adicionado ao arquivo de transações com sucesso." << std::endl;
    } else {
        std::cout << "Erro ao abrir o arquivo de transações." << std::endl;
    }
}

int main() {
    Registro novoRegistro;

    std::cout << "Digite o ID do novo registro: ";
    std::cin >> novoRegistro.id;

    std::cin.ignore(); // Limpar o buffer do teclado

    std::cout << "Digite o nome do novo registro: ";
    std::getline(std::cin, novoRegistro.nome);

    std::cout << "Digite o email do novo registro: ";
    std::getline(std::cin, novoRegistro.email);

    incluirRegistro(novoRegistro);

    return 0;
}
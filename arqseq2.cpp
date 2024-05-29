#include <iostream>
#include <fstream>
#include <string>

struct Registro {
    int codigo;
    std::string nome;
    std::string endereco;
    std::string cidade;
    std::string uf;
};

void lerDados(Registro& registro, std::ifstream& arquivo) {
    arquivo >> registro.codigo;
    arquivo.ignore(); // Ignorar o caractere de separação
    std::getline(arquivo, registro.nome, ',');
    std::getline(arquivo, registro.endereco, ',');
    std::getline(arquivo, registro.cidade, ',');
    std::getline(arquivo, registro.uf);
}

void percorrerRegistros(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    Registro registro;
    while (!arquivo.eof()) {
        lerDados(registro, arquivo);
        std::cout << "Código: " << registro.codigo << std::endl;
        std::cout << "Nome: " << registro.nome << std::endl;
        std::cout << "Endereço: " << registro.endereco << std::endl;
        std::cout << "Cidade: " << registro.cidade << std::endl;
        std::cout << "UF: " << registro.uf << std::endl;
        std::cout << std::endl;
    }

    arquivo.close();
}

int main() {
    std::string nomeArquivo = "caminho/do/arquivo.txt";
    percorrerRegistros(nomeArquivo);

    return 0;
}
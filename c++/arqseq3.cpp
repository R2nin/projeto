<<<<<<<<<<<<<<  ✨ Codeium Command ⭐ >>>>>>>>>>>>>>>>
#include <iostream>
#include <fstream>

struct Registro {
    int codigo;
    std::string nome;
    std::string endereco;
    std::string cidade;
    std::string uf;
};

void percorrerRegistros(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    Registro registro;
    while (!arquivo.eof()) {
        arquivo >> registro.codigo;
        getline(arquivo, registro.nome, ',');
        getline(arquivo, registro.endereco, ',');
        getline(arquivo, registro.cidade, ',');
        getline(arquivo, registro.uf);

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
    percorrerRegistros("registros.dat");

    return 0;
}


<<<<<<<  2f23385a-8e92-475b-ab05-a88f03807b56  >>>>>>>
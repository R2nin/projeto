#include <iostream>
#include <fstream>
#include <string>

struct Registro {
    int codigo;
    std::string nome;
    std::string endereco;
    std::string cidade;
    std::string UF;
};
#include <vector>

void lerDados(const std::string& nomeArquivo, std::vector<Registro>& registros) {
    std::ifstream arquivo(nomeArquivo, std::ios::in | std::ios::binary);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    Registro registro;
    while (arquivo.read(reinterpret_cast<char*>(&registro), sizeof(Registro))) {
        registros.push_back(registro);
    }

    arquivo.close();
}
void percorrerRegistros(const std::vector<Registro>& registros) {
    for (const auto& registro : registros) {
        std::cout << "Código: " << registro.codigo << std::endl;
        std::cout << "Nome: " << registro.nome << std::endl;
        std::cout << "Endereço: " << registro.endereco << std::endl;
        std::cout << "Cidade: " << registro.cidade << std::endl;
        std::cout << "UF: " << registro.UF << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
int main() {
    std::string nomeArquivo = "registros.dat"; // Substitua pelo nome do seu arquivo
    std::vector<Registro> registros;

    lerDados(nomeArquivo, registros);
    percorrerRegistros(registros);

    return 0;
}

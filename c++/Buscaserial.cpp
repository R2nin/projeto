#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Cadastro {
    int codigo;
    string nome, endereco, cidade, UF;
};

int main() {
    Cadastro registro;
    ifstream arquivo("registros.dat", ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 0;
    }

    while (arquivo.read(reinterpret_cast<char*>(&registro), sizeof(Cadastro))) {
        cout << "C�digo: " << registro.codigo << endl;
        cout << "Nome: " << registro.nome << endl;
        cout << "Endere�o: " << registro.endereco << endl;
        cout << "Cidade: " << registro.cidade << endl;
        cout << "UF: " << registro.UF << endl;
        cout << "------------------------" << endl;
    }

    arquivo.close();

    int codigoBuscado;
    cout << "Digite o c�digo a ser buscado: ";
    cin >> codigoBuscado;

    // Reabrindo o arquivo
    arquivo.open("registros.dat", ios::binary);

    bool achou = false;
    while (!arquivo.eof() && !achou) {
        arquivo.read(reinterpret_cast<char*>(&registro), sizeof(Cadastro));
        if (registro.codigo == codigoBuscado) {
            achou = true;
            cout << "Registro encontrado!" << endl;
            cout << "C�digo: " << registro.codigo << endl;
            cout << "Nome: " << registro.nome << endl;
            cout << "Endere�o: " << registro.endereco << endl;
            cout << "Cidade: " << registro.cidade << endl;
            cout << "UF: " << registro.UF << endl;
        }
    }

    if (!achou)
        cout << "Registro n�o encontrado" << endl;

    arquivo.close();

    return 0;
}

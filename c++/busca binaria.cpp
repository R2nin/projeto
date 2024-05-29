#include <iostream>
#include <algorithm>
using namespace std;

struct clientes {
    int codigo;
    char nome[30];
    char endereco[35];
    char cidade[25];
    char uf[2];
};

void leitura (struct clientes cli[]){
    for (int i = 0; i < 10; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> cli[i].codigo;
        cout << "Nome: ";
        cin >> cli[i].nome;
        cout << "Endereco: ";
        cin >> cli[i].endereco;
        cout << "Cidade: ";
        cin >> cli[i].cidade;
        cout << "Estado: ";
        cin >> cli[i].uf;
    }
    // Ordena o array de clientes pelo código
    sort(cli, cli + 10, [](const clientes& a, const clientes& b) {
        return a.codigo < b.codigo;
    });
}

void buscaBinaria (struct clientes cli[], int cod){
    int inicio = 0;
    int fim = 9;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (cli[meio].codigo == cod) {
            cout << "\n\n Cliente Encontrado";
            cout << "\nCodigo do Cliente: " << cli[meio].codigo;
            cout << "\tNome: " << cli[meio].nome;
            cout << "\tEndereco: " << cli[meio].endereco;
            cout << "\tCidade: " << cli[meio].cidade;
            cout << "\tEstado: " << cli[meio].uf;
            return;
        }
        if (cli[meio].codigo < cod) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    cout << "\n\n Cliente nao Encontrado";
}

int main(){
    struct clientes arqclientes[10];
    int codpesq;
    leitura (arqclientes);
    for (codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cliente a ser Buscado: ";
        cin >> codpesq;
        if (codpesq != 0)
            buscaBinaria (arqclientes, codpesq);
    }
}
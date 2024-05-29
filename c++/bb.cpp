#include <iostream>
#include <conio.h>
using namespace std;
/* Busca Aleat�ria = Busca Bin�ria
*/

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
}

void busca_aleat (struct clientes cli[], int cod){
    int i = 0, f = 10;
    int m = (i + f) / 2;
    for (; f >= i && cod != cli[m].codigo; m = (i + f) / 2){
        if (cod > cli[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == cli[m].codigo){
        cout << "\n\n Cliente Encontrado";
        cout << "\nCodigo do Cliente: " << cli[m].codigo;
        cout << "\tNome: " << cli[m].nome;
        cout << "\tEndereco: " << cli[m].endereco;
        cout << "\tCidade: " << cli[m].cidade;
        cout << "\tEstado: " << cli[m].uf;
    }
    else
        cout << "\n\n Cliente nao Encontrado";
    getch();
}
int main(){
    struct clientes arqclientes[10];
    int codpesq;
    leitura (arqclientes);
    for (codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cliente a ser Buscado: ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_aleat(arqclientes, codpesq);
    }
}
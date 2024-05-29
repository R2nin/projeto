#include <iostream>
#include <conio.h>
using namespace std;
/* Implementar um programa em C++ que percorra os registros de um arquivo sequencial,
mostrando suas informa��es, desde o primeiro registro at� o ultimo.
Para simular a estrutura de um arquivo sequencial, utilize uma estrutura (Struct).
Crie uma fun��o espec�fica para a leitura dos dados e outra fun��o espec�fica para
o percurso dos registros.
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

void buscaserial (struct clientes cli[], int cod){
    int i = 0;
    for (; i < 10 && cod > cli[i].codigo; i++);
    if (cod == cli[i].codigo){
        cout << "\n\n Cliente Encontrado";
        cout << "\nCodigo do Cliente: " << cli[i].codigo;
        cout << "\tNome: " << cli[i].nome;
        cout << "\tEndereco: " << cli[i].endereco;
        cout << "\tCidade: " << cli[i].cidade;
        cout << "\tEstado: " << cli[i].uf;
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
            buscaserial (arqclientes, codpesq);
    }
}
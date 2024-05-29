#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
/* Exclusao de registros Arquivo Sequencial
*/

struct clientes {
       int codigo;
       char nome[30];
       char endereco[35];
       char cidade[25];
       char uf[2];
       };

void leitura (struct clientes cli[], int &contador){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> cli[i].codigo;
        if (cli[i].codigo > 0){
            cout << "Nome: ";
            cin >> cli[i].nome;
            cout << "Endereco: ";
            cin >> cli[i].endereco;
            cout << "Cidade: ";
            cin >> cli[i].cidade;
            cout << "Estado: ";
            cin >> cli[i].uf;
        }
        else saida = 0;
    }
    contador = i-1;
}
void exclusao(struct clientes S[], int contS, struct clientes T[], int contT, struct clientes A[], int &contA) {
    int i = 0, j = 0, k = 0; // i (contador de S), j (contador de T), k (contador de A)
    while (i < contS && j < contT) {
        if (S[i].codigo < T[j].codigo) {
            A[k].codigo = S[i].codigo;
            strcpy(A[k].nome, S[i].nome);
            strcpy(A[k].endereco, S[i].endereco);
            strcpy(A[k].cidade, S[i].cidade);
            strcpy(A[k].uf, S[i].uf);
            i++;
            k++;
        } else if (T[j].codigo < S[i].codigo) {
            j++;
        } else { // S[i].codigo == T[j].codigo, exclui registro
            i++;
            j++;
        }
    }
    while (i < contS) {
        A[k].codigo = S[i].codigo;
        strcpy(A[k].nome, S[i].nome);
        strcpy(A[k].endereco, S[i].endereco);
        strcpy(A[k].cidade, S[i].cidade);
        strcpy(A[k].uf, S[i].uf);
        i++;
        k++;
    }
    contA = k;
}
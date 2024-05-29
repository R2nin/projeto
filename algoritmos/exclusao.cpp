#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
/* Exclus�o de registros Arquivo Sequencial
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

void exclusao (struct clientes S[], int contS, int T[], int contT, struct clientes A[], int &contA){
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (;j < contT; i++){
        if (S[i].codigo != T[j]){
            A[k].codigo = S[i].codigo;
            strcpy (A[k].nome,S[i].nome);
            strcpy (A[k].endereco,S[i].endereco);
            strcpy (A[k].cidade,S[i].cidade);
            strcpy (A[k].uf,S[i].uf);
            k++;
            }
        else {
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        strcpy (A[k].nome,S[i].nome);
        strcpy (A[k].endereco,S[i].endereco);
        strcpy (A[k].cidade,S[i].cidade);
        strcpy (A[k].uf,S[i].uf);
        i++;
        k++;
    }
    contA = k;
}
void mostrar (struct clientes A[], int contA){
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].codigo;
        cout << "\tNome: " << A[i].nome;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tCidade: " << A[i].cidade;
        cout << "\tUF: " << A[i].uf;
    }
}
int main(){
    struct clientes arqS[20], arqA[40];
    int arqT[20];
    int contS, contT, contA;
    cout << "\n\nLeitura do Arquivo S";
    leitura (arqS,contS);
    cout << "\n\nLeitura do Arquivo T";
    for (contT = 0; contT < 20 && arqT[contT - 1] > 0; contT++){
        cout << "\nInforme o Codigo do Registro a ser Excluido (finalize com 0): ";
        cin >> arqT[contT];
    }
    contT--;
    exclusao (arqS, contS, arqT, contT, arqA, contA);
    mostrar (arqA, contA);
    getch();
}
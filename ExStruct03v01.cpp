#include <iostream>
#include <string>

using namespace std;

struct Contato {
    string nome;
    string telefone;
    string email;
};

int main() {
    Contato contatos[10];
    int numContatos = 0;

    while (true) {
        cout << "Escolha uma opção:\n";
        cout << "1 - Adicionar contato\n";
        cout << "2 - Listar contatos\n";
        cout << "3 - Procurar telefone de um contato\n";
        cout << "4 - Sair\n";

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            if (numContatos >= 10) {
                cout << "Não é possível adicionar mais contatos.\n";
            } else {
                Contato novoContato;
                cout << "Digite o nome do contato: ";
                cin >> novoContato.nome;
                cout << "Digite o telefone do contato: ";
                cin >> novoContato.telefone;
                cout << "Digite o e-mail do contato: ";
                cin >> novoContato.email;

                contatos[numContatos] = novoContato;
                numContatos++;

                cout << "Contato adicionado com sucesso!\n";
            }
        } else if (opcao == 2) {
            if (numContatos == 0) {
                cout << "Não há contatos cadastrados.\n";
            } else {
                cout << "Lista de contatos:\n";
                for (int i = 0; i < numContatos; i++) {
                    cout << "Nome: " << contatos[i].nome << endl;
                    cout << "Telefone: " << contatos[i].telefone << endl;
                    cout << "E-mail: " << contatos[i].email << endl;
                    cout << endl;
                }
            }
        } else if (opcao == 3) {
            if (numContatos == 0) {
                cout << "Não há contatos cadastrados.\n";
            } else {
                string nomeProcurado;
                cout << "Digite o nome do contato: ";
                cin >> nomeProcurado;

                bool encontrado = false;
                for (int i = 0; i < numContatos; i++) {
                    if (contatos[i].nome == nomeProcurado) {
                        cout << "Telefone do contato " << nomeProcurado << ": " << contatos[i].telefone << endl;
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Contato não encontrado.\n";
                }
            }
        } else if (opcao == 4) {
            break;
        } else {
            cout << "Opção inválida.\n";
        }

        cout << endl;
    }

    return 0;
}

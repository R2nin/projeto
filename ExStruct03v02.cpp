#include <iostream>
#include <string>

struct Contato {
    std::string nome;
    std::string telefone;
    std::string email;
};

int main() {
    Contato contatos[10];
    int numContatos = 0;

    int opcao;
    do {
        std::cout << "Selecione uma opcao:" << std::endl;
        std::cout << "1. Adicionar contato" << std::endl;
        std::cout << "2. Listar contatos" << std::endl;
        std::cout << "3. Procurar telefone de um contato" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                if (numContatos < 10) {
                    Contato novoContato;
                    std::cout << "Nome: ";
                    std::cin.ignore();
                    std::getline(std::cin, novoContato.nome);
                    std::cout << "Telefone: ";
                    std::getline(std::cin, novoContato.telefone);
                    std::cout << "Email: ";
                    std::getline(std::cin, novoContato.email);

                    contatos[numContatos] = novoContato;
                    numContatos++;
                } else {
                    std::cout << "Limite máximo de contatos atingido!" << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Lista de contatos:" << std::endl;
                for (int i = 0; i < numContatos; i++) {
                    std::cout << "Nome: " << contatos[i].nome << std::endl;
                    std::cout << "Telefone: " << contatos[i].telefone << std::endl;
                    std::cout << "Email: " << contatos[i].email << std::endl;
                    std::cout << std::endl;
                }
                break;
            }
            case 3: {
                std::string nomeProcurado;
                std::cout << "Nome do contato: ";
                std::cin.ignore();
                std::getline(std::cin, nomeProcurado);

                bool contatoEncontrado = false;
                for (int i = 0; i < numContatos; i++) {
                    if (contatos[i].nome == nomeProcurado) {
                        std::cout << "Telefone: " << contatos[i].telefone << std::endl;
                        contatoEncontrado = true;
                        break;
                    }
                }

                if (!contatoEncontrado) {
                    std::cout << "Contato nao encontrado!" << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcao != 0);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

struct Funcionario {
    std::string nome;
    int identificacao;
    double salario;
    std::string departamento;
};

int main() {
    
    std::vector<Funcionario> funcionarios;

    int opcao;
    do {
        std::cout << "Selecione uma opcao:" << std::endl;
        std::cout << "1. Cadastrar funcionario" << std::endl;
        std::cout << "2. Calcular total de salarios em um departamento" << std::endl;
        std::cout << "3. Listar todos os funcionarios" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                Funcionario novoFuncionario;
                std::cout << "Nome: ";
                std::cin.ignore();
                std::getline(std::cin, novoFuncionario.nome);
                std::cout << "Identificacao: ";
                std::cin >> novoFuncionario.identificacao;
                std::cout << "Salario: ";
                std::cin >> novoFuncionario.salario;
                std::cout << "Departamento: ";
                std::cin.ignore();
                std::getline(std::cin, novoFuncionario.departamento);

                funcionarios.push_back(novoFuncionario);
                break;
            }
            case 2: {
                std::string departamento;
                std::cout << "Departamento: ";
                std::cin.ignore();
                std::getline(std::cin, departamento);

                double totalSalarios = 0;
                for (const auto& funcionario : funcionarios) {
                    if (funcionario.departamento == departamento) {
                        totalSalarios += funcionario.salario;
                    }
                }

                std::cout << "Total de salarios em " << departamento << ": " << totalSalarios << std::endl;
                break;
            }
            case 3: {
                std::cout << "Lista de funcionarios:" << std::endl;
                for (const auto& funcionario : funcionarios) {
                    std::cout << "Nome: " << funcionario.nome << std::endl;
                    std::cout << "Identificacao: " << funcionario.identificacao << std::endl;
                    std::cout << "Salario: " << funcionario.salario << std::endl;
                    std::cout << "Departamento: " << funcionario.departamento << std::endl;
                    std::cout << std::endl;
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
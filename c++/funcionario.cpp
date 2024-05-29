#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definição da estrutura Funcionario
struct Funcionario {
    string nome;
    int id;
    double salario;
    string departamento;
};

// Função para cadastrar informações de funcionários
void cadastrarFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o nome do funcionário: ";
    getline(cin, novoFuncionario.nome);
    cout << "Digite o número de identificação do funcionário: ";
    cin >> novoFuncionario.id;
    cout << "Digite o salário do funcionário: ";
    cin >> novoFuncionario.salario;
    cout << "Digite o departamento do funcionário: ";
    cin.ignore();
    getline(cin, novoFuncionario.departamento);
    funcionarios.push_back(novoFuncionario);
    cout << "Funcionário cadastrado com sucesso!" << endl;
}

// Função para calcular o total de salários em um departamento específico
double calcularTotalSalarios(vector<Funcionario>& funcionarios, string departamento) {
    double totalSalarios = 0;
    for (Funcionario funcionario : funcionarios) {
        if (funcionario.departamento == departamento) {
            totalSalarios += funcionario.salario;
        }
    }
    return totalSalarios;
}

// Função para listar todos os funcionários
void listarFuncionarios(vector<Funcionario>& funcionarios) {
    cout << "Lista de funcionários:" << endl;
    for (Funcionario funcionario : funcionarios) {
        cout << "Nome: " << funcionario.nome << endl;
        cout << "ID: " << funcionario.id << endl;
        cout << "Salário: " << funcionario.salario << endl;
        cout << "Departamento: " << funcionario.departamento << endl;
        cout << endl;
    }
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;
    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Cadastrar funcionário" << endl;
        cout << "2 - Calcular total de salários em um departamento específico" << endl;
        cout << "3 - Listar todos os funcionários" << endl;
        cout << "4 - Sair" << endl;
        cin >> opcao;
        string departamento; // move declaration outside of switch block
        switch (opcao) {
            case 1:
                cadastrarFuncionario(funcionarios);
                break;
            case 2:
                cout << "Digite o nome do departamento: ";
                cin.ignore(); // clear input buffer
                getline(cin, departamento);
                cout << "Total de salários no departamento " << departamento << ": " << calcularTotalSalarios(funcionarios, departamento) << endl;
                break;
            case 3:
                listarFuncionarios(funcionarios);
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }

            case 1:
                cadastrarFuncionario(funcionarios);
                break;
            case 2:
                string departamento;
                cout << "Digite o nome do departamento: ";
                cin.ignore();
                getline(cin, departamento);
                cout << "Total de salários no departamento " << departamento << ": " << calcularTotalSalarios(funcionarios, departamento) << endl;
                break;
            case 3:
                listarFuncionarios(funcionarios);
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 4);
    return 0;
}

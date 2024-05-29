#include <iostream>
#include <cstring>
using namespace std;

struct Funcionario {
    char nome[50];
    int id;
    double salario;
    char departamento[50];
};

int main() {
    int n;
    cout << "Quantos funcionarios deseja cadastrar? ";
    cin >> n;
    
    Funcionario funcionarios[n];
    
    for (int i = 0; i < n; i++) {
        cout << "\nFuncionario " << i+1 << endl;
        cout << "Nome: ";
        cin >> funcionarios[i].nome;
        cout << "ID: ";
        cin >> funcionarios[i].id;
        cout << "Salario: ";
        cin >> funcionarios[i].salario;
        cout << "Departamento: ";
        cin >> funcionarios[i].departamento;
    }
    
    char departamento[50];
    cout << "\nDigite o nome do departamento para calcular o total de salario: ";
    cin >> departamento;
    
    double totalSalario = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(funcionarios[i].departamento, departamento) == 0) {
            totalSalario += funcionarios[i].salario;
        }
    }
    
    cout << "\nTotal de salario do departamento " << departamento << ": " << totalSalario << endl;
    
    cout << "\nFuncionarios cadastrados:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nFuncionario " << i+1 << endl;
        cout << "Nome: " << funcionarios[i].nome << endl;
        cout << "ID: " << funcionarios[i].id << endl;
        cout << "Salario: " << funcionarios[i].salario << endl;
        cout << "Departamento: " << funcionarios[i].departamento << endl;
    }
    
    return 0;
}
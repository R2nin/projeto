#include <iostream>
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
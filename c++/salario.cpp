#include <iostream>
using namespace std;

int main() {
    float salario, gratificacao, imposto, salario_total = 0, imposto_total = 0;

    for (int i = 1; i <= 50; i++) {
        cout << "Informe o salário base do funcionário " << i << ": ";
        cin >> salario;

        gratificacao = 0.16 * salario;
        imposto = 0.30 * salario;

        salario_total += salario + gratificacao - imposto;
        imposto_total += imposto;
    }

    cout << "Valor pago aos 50 funcionários: R$" << salario_total << endl;
    cout << "Total de imposto descontado: R$" << imposto_total << endl;

    return 0;
}
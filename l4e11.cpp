#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> vNome;
    std::vector<int> vPulso;
    const int numFuncionarios = 10;

    // Read names and pulse quantities for each employee
    for (int i = 0; i < numFuncionarios; i++) {
        std::string nome;
        int pulso;

        std::cout << "Digite o nome do funcionario " << i+1 << ": ";
        std::cin >> nome;

        std::cout << "Digite a quantidade de pulsos telefonicos gastos por " << nome << ": ";
        std::cin >> pulso;

        vNome.push_back(nome);
        vPulso.push_back(pulso);
    }

    std::cout << "Funcionarios que consumiram mais de 200 pulsos:" << std::endl;
    for (int i = 0; i < numFuncionarios; i++) {
        if (vPulso[i] > 200) {
            std::cout << vNome[i] << std::endl;
        }
    }

    int somaPulsos = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        somaPulsos += vPulso[i];
    }

    double mediaPulsos = static_cast<double>(somaPulsos) / numFuncionarios;

    std::cout << "Media de consumo da empresa: " << mediaPulsos << " pulsos" << std::endl;

    int menorPulso = vPulso[0];
    for (int i = 1; i < numFuncionarios; i++) {
        if (vPulso[i] < menorPulso) {
            menorPulso = vPulso[i];
        }
    }

    std::cout << "Menor valor de pulsos: " << menorPulso << std::endl;

    std::sort(vPulso.begin(), vPulso.end());

    std::cout << "Valores de pulsos em ordem crescente de consumo:" << std::endl;
    for (int i = 0; i < numFuncionarios; i++) {
        std::cout << vPulso[i] << std::endl;
    }

    return 0;
}

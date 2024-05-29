#include <iostream>

struct Data {
    int dia;
    int mes;
    int ano;
};

bool isAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool isDataValida(const Data& data) {
    if (data.ano < 0) {
        return false;
    }

    if (data.mes < 1 || data.mes > 12) {
        return false;
    }

    if (data.dia < 1) {
        return false;
    }

    int diasNoMes = 0;
    switch (data.mes) {
        case 1: // Janeiro
        case 3: // Março
        case 5: // Maio
        case 7: // Julho
        case 8: // Agosto
        case 10: // Outubro
        case 12: // Dezembro
            diasNoMes = 31;
            break;
        case 4: // Abril
        case 6: // Junho
        case 9: // Setembro
        case 11: // Novembro
            diasNoMes = 30;
            break;
        case 2: // Fevereiro
            diasNoMes = isAnoBissexto(data.ano) ? 29 : 28;
            break;
    }

    return data.dia <= diasNoMes;
}

int main() {
    Data data;

    std::cout << "Digite uma data (dia mes ano): ";
    std::cin >> data.dia >> data.mes >> data.ano;

    if (isDataValida(data)) {
        std::cout << "Data valida!" << std::endl;
    } else {
        std::cout << "Data invalida!" << std::endl;
    }

    return 0;
}
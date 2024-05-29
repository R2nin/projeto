#include <iostream>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

bool ehBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

bool ehDataValida(Data data) {
    if (data.mes < 1 || data.mes > 12) {
        return false;
    } else if (data.dia < 1 || data.dia > 31) {
        return false;
    } else if (data.mes == 2) {
        if (ehBissexto(data.ano)) {
            if (data.dia > 29) {
                return false;
            }
        } else {
            if (data.dia > 28) {
                return false;
            }
        }
    } else if ((data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) && data.dia > 30) {
        return false;
    }
    return true;
}

int main() {
    Data data;
    cout << "Digite o dia: ";
    cin >> data.dia;
    cout << "Digite o mes: ";
    cin >> data.mes;
    cout << "Digite o ano: ";
    cin >> data.ano;

    if (ehDataValida(data)) {
        cout << "Data valida!" << endl;
    } else {
        cout << "Data invalida!" << endl;
    }

    return 0;
}

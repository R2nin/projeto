//Faça um programa que leia duas datas no formato DD/MM/AAAA e calcule a diferença em anos e meses e dias.
#include <iostream>
#include <sstream>

struct Date {
    int day;
    int month;
    int year;
};

// Função para converter a string no formato "DD/MM/AAAA" para uma estrutura Date
Date parseDate(const std::string& dateStr) {
    Date date;
    std::istringstream iss(dateStr);
    char delimiter;
    iss >> date.day >> delimiter >> date.month >> delimiter >> date.year;
    return date;
}

// Função para calcular a diferença entre duas datas em anos, meses e dias
void calculateDateDifference(const Date& date1, const Date& date2, int& diffYears, int& diffMonths, int& diffDays) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        diffYears = diffMonths = diffDays = 0;
        return;
    }

    if (date1.year > date2.year || (date1.year == date2.year && date1.month > date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)) {
        // Swap dates if date1 is later than date2
        calculateDateDifference(date2, date1, diffYears, diffMonths, diffDays);
        return;
    }

    diffYears = date2.year - date1.year;
    diffMonths = date2.month - date1.month;
    diffDays = date2.day - date1.day;

    if (diffDays < 0) {
        // Borrow days from months
        diffDays += 30; // Assuming each month has 30 days for simplicity
        diffMonths--;
    }

    if (diffMonths < 0) {
        // Borrow months from years
        diffMonths += 12;
        diffYears--;
    }
}

int main() {
    std::string dateStr1, dateStr2;
    std::cout << "Digite a primeira data no formato DD/MM/AAAA: ";
    std::cin >> dateStr1;

    std::cout << "Digite a segunda data no formato DD/MM/AAAA: ";
    std::cin >> dateStr2;

    Date date1 = parseDate(dateStr1);
    Date date2 = parseDate(dateStr2);

    int diffYears, diffMonths, diffDays;
    calculateDateDifference(date1, date2, diffYears, diffMonths, diffDays);

    std::cout << "Diferenca em anos: " << diffYears << std::endl;
    std::cout << "Diferenca em meses: " << diffMonths << std::endl;
    std::cout << "Diferenca em dias: " << diffDays << std::endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // Definir a matriz A[5x4]
    int A[5][4];

    // Ler os valores da matriz A
    cout << "Digite os valores da matriz A[5x4]:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> A[i][j];
        }
    }

    for (int j = 0; j < 4; j++)
    for (int i = 0; i < 5; i++) {
         {
           cout << A[i][j] << " ";
        } cout << endl;
            }

       return 0;
    }

 

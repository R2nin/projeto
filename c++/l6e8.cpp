#include <iostream>
#include <iomanip>

int main() {
  int pan[6][6];

  // Leitura dos dados
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << "Digite a quantidade de pontos para o pais " << i << " no dia " << j << ": ";
      std::cin >> pan[i][j];
    }
  }

  int menorPontuacao = pan[0][0];
  int somaPontos = 0;
  int quantidadePontosMenores30 = 0;
  int somaAbaixoDiagonal = 0;
  int somaColunasImpares = 0;
  int quantidadeColunasImpares = 0;

  // Cálculos
  for (int i = 0; i < 6; i++) {
    int somaLinha = 0;
    for (int j = 0; j < 6; j++) {
      somaLinha += pan[i][j];

      if (pan[i][j] < 30) {
        quantidadePontosMenores30++;
      }

      if (j < i) {
        somaAbaixoDiagonal += pan[i][j];
      }

      if (j % 2 == 1) {
        somaColunasImpares += pan[i][j];
        quantidadeColunasImpares++;
      }
    }

    if (somaLinha < menorPontuacao) {
      menorPontuacao = somaLinha;
    }
    somaPontos += somaLinha;
  }

  double mediaPontosPorDia = static_cast<double>(somaPontos) / 6;
  double mediaColunasImpares = static_cast<double>(somaColunasImpares) / quantidadeColunasImpares;

  std::cout << "O país com menor quantidade de pontos é: " << menorPontuacao << std::endl;
  std::cout << "O percentual de pontos menores que 30 é: " << std::fixed << std::setprecision(2) << static_cast<double>(quantidadePontosMenores30) / 36 * 100 << "%" << std::endl;
  std::cout << "A soma dos valores abaixo da diagonal principal é: " << somaAbaixoDiagonal << std::endl;
  std::cout << "A média de valores nas colunas ímpares é: " << std::fixed << std::setprecision(2) << mediaColunasImpares << std::endl;

  std::cout << "A média de pontos por dia é: " << std::fixed << std::setprecision(2) << mediaPontosPorDia << std::endl;

  return 0;
}
# Exercício 1 - Fatorial
n = int(input("Digite o valor de n: "))

# Inicializa o fatorial com 1
fatorial = 1

# Calcula o fatorial
for i in range(1, n + 1):
    fatorial *= i

print(fatorial)

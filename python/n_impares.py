# Exercício 2 - Números ímpares naturais
n = int(input("Digite o valor de n: "))

# Inicializa o contador e o primeiro número ímpar
contador = 0
numero_impar = 1

# Imprime os n primeiros números ímpares naturais
while contador < n:
    print(numero_impar)
    numero_impar += 2
    contador += 1

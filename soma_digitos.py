# Exercício 3 - Soma dos dígitos
num = int(input("Digite um número inteiro: "))

# Inicializa a variável para armazenar a soma
soma = 0

# Calcula a soma dos dígitos
while num > 0:
    digito = num % 10
    soma += digito
    num //= 10

print(soma)

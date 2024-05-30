# Solicitar coeficientes e termos independentes das equações
a1 = float(input("Digite o coeficiente a1 da equação para x: "))
b1 = float(input("Digite o coeficiente b1 da equação para x: "))
c1 = float(input("Digite o coeficiente c1 da equação para x: "))
d1 = float(input("Digite o termo independente d1 da equação para x: "))

a2 = float(input("Digite o coeficiente a2 da equação para y: "))
b2 = float(input("Digite o coeficiente b2 da equação para y: "))
c2 = float(input("Digite o coeficiente c2 da equação para y: "))
d2 = float(input("Digite o termo independente d2 da equação para y: "))

a3 = float(input("Digite o coeficiente a3 da equação para z: "))
b3 = float(input("Digite o coeficiente b3 da equação para z: "))
c3 = float(input("Digite o coeficiente c3 da equação para z: "))
d3 = float(input("Digite o termo independente d3 da equação para z: "))

# Solicitar o erro máximo
erro_maximo = float(input("Digite o erro máximo tolerado: "))

# Definir valores iniciais
x = float(input("Digite o valor inicial de x: "))
y = float(input("Digite o valor inicial de y: "))
z = float(input("Digite o valor inicial de z: "))

def calcular_x(x_anterior, y_anterior, z_anterior, a1, b1, c1, d1):
    """
    Calcula o novo valor de x usando o método de Gauss-Seidel.

    Args:
        x_anterior: Valor anterior de x.
        y_anterior: Valor anterior de y.
        z_anterior: Valor anterior de z.
        a1: Coeficiente a1 da equação para x.
        b1: Coeficiente b1 da equação para x.
        c1: Coeficiente c1 da equação para x.
        d1: Termo independente d1 da equação para x.

    Returns:
        Novo valor de x.
    """
    novo_x = (d1 - b1 * y_anterior - c1 * z_anterior) / a1
    return novo_x

def calcular_y_e_z(x, y_anterior, z_anterior, a2, b2, c2, d2, a3, b3, c3, d3):
    """
    Calcula os novos valores de y e z usando o método de Gauss-Seidel.

    Args:
        x: Valor atual de x.
        y_anterior: Valor anterior de y.
        z_anterior: Valor anterior de z.
        a2: Coeficiente a2 da equação para y.
        b2: Coeficiente b2 da equação para y.
        c2: Coeficiente c2 da equação para y.
        d2: Termo independente d2 da equação para y.
        a3: Coeficiente a3 da equação para z.
        b3: Coeficiente b3 da equação para z.
        c3: Coeficiente c3 da equação para z.
        d3: Termo independente d3 da equação para z.

    Returns:
        Tupla com os novos valores de y e z.
    """
    novo_y = (d2 - a2 * x - c2 * z_anterior) / b2
    novo_z = (d3 - a3 * x - b3 * y_anterior) / c3
    return novo_y, novo_z

# Loop de iteração com controle do usuário
solucoes = []  # Lista para armazenar as soluções intermediárias

while True:
    # Calcular novos valores de x, y e z
    novo_x = calcular_x(x, y, z, a1, b1, c1, d1)
    novo_y, novo_z = calcular_y_e_z(novo_x, y, z, a2, b2, c2, d2, a3, b3, c3, d3)

    # Verificar critério de convergência
    if abs(novo_x - x) < erro_maximo and abs(novo_y - y) < erro_maximo and abs(novo_z - z) < erro_maximo:
        break

    # Atualizar valores para a próxima iteração
    x = novo_x
    y = novo_y
    z = novo_z

    # Armazenar solução intermediária
    i=0
    solucoes.append((novo_x, novo_y, novo_z))
    
    for solucao in solucoes:
        print("\nSoluções intermediárias:", i)
        print("x =", solucao[0])
        print("y =", solucao[1])
        print("z =", solucao[2])
        i=i+1
    # Perguntar ao usuário se deseja continuar
    continuar = input("Deseja continuar? (Digite 's' para sim ou 'f' para parar): ")
    if continuar.lower() == "f":
        break

# Exibir os resultados

print("\nSolução final:")
print("x =", x)
print("y =", y)
print("z =", z)


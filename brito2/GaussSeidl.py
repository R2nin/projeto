import sys
# Solicitar coeficientes e termos independentes das equações
a1 = float(input("Digite o coeficiente a11 da equação para Eq1: "))
b1 = float(input("Digite o coeficiente a12 da equação para Eq1: "))
c1 = float(input("Digite o coeficiente a13 da equação para Eq1: "))
d1 = float(input("Digite o termo independente d1 da equação para Eq1: "))

a2 = float(input("Digite o coeficiente a21 da equação para Eq2: "))
b2 = float(input("Digite o coeficiente a22 da equação para Eq2: "))
c2 = float(input("Digite o coeficiente a23 da equação para Eq2: "))
d2 = float(input("Digite o termo independente d2 da equação para Eq2: "))

a3 = float(input("Digite o coeficiente a31 da equação para Eq3: "))
b3 = float(input("Digite o coeficiente a32 da equação para Eq3: "))
c3 = float(input("Digite o coeficiente a33 da equação para Eq3: "))
d3 = float(input("Digite o termo independente d3 da equação para Eq3: "))
Beta1 = abs((b1+c1)/a1)
Beta2 = abs((a2*Beta1+c2)/b2)
Beta3 = abs((a3*Beta1+b3*Beta2)/c3)
print("Beta1 = ", Beta1)
print("Beta2 = ", Beta2)
print("Beta3 = ", Beta3)
if Beta1 < 1 and Beta2 < 1 and Beta3 < 1:
    print("O sistema é convergente")
else:
    print("O sistema é divergente")
    sys.exit(0)
# Solicitar o erro máximo
erro_maximo = float(input("Digite o erro máximo tolerado: "))

# Definir valores iniciais
x = d1/a1
y = d2/b2
z = d3/c3
print("x =", x)
print("y =", y)
print("z =", z)
def calcular_x(x_anterior, y_anterior, z_anterior, a1, b1, c1, d1):
    """
    Calcula o novo valor de x usando o método de Gauss-Seidel

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
print("x =", round(x,4))
print("y =", round(y,4))
print("z =", round(z,4))

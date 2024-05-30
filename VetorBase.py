def ler_vetor(nome_vetor):
    """
    Lê um vetor de 2 elementos fornecidos pelo usuário.

    Args:
        nome_vetor (str): Nome do vetor para identificação durante a entrada.

    Returns:
        list: Vetor com 2 elementos inseridos pelo usuário.
    """
    vetor = []
    for i in range(2):
        elemento = float(input(f"Digite o elemento {i+1} do {nome_vetor}: "))
        vetor.append(elemento)
    return vetor

def calcular_determinante(vetor1, vetor2):
    a, b = vetor1
    c, d = vetor2
    return a * d - b * c

def formatar_vetor(vetor):
    return [f"{elemento:.4f}" for elemento in vetor]

while True:
    vetor1 = ler_vetor("vetor 1")
    vetor2 = ler_vetor("vetor 2")

    vetor1_formatado = formatar_vetor(vetor1)
    vetor2_formatado = formatar_vetor(vetor2)

    Det = calcular_determinante(vetor1, vetor2)

    print("\nOs vetores lidos são:")
    print("Vetor 1:", vetor1_formatado)
    print("Vetor 2:", vetor2_formatado)
    print(f"\nO valor do determinante é: {Det:.4f}")

    if Det == 0:
        print("Vetores linearmente dependentes")
    else:
        vetor3 = ler_vetor("vetor 3")
        vetor3_formatado = formatar_vetor(vetor3)
        print("Vetor 3:", vetor3_formatado)

        e, f = vetor3
        DetA1 = calcular_determinante([e, f], vetor2)
        DetB1 = calcular_determinante(vetor1, [e, f])

        A1 = DetA1 / Det
        B1 = DetB1 / Det

        print(f"\nO valor de A1 é: {A1:.4f}")
        print(f"O valor de B1 é: {B1:.4f}")

        # Verifica se v3 = A1 * v1 + B1 * v2
        v3 = [A1 * elemento1 + B1 * elemento2 for elemento1, elemento2 in zip(vetor1, vetor2)]
        v3_formatado = formatar_vetor(v3)
        print("Resultado de v3 (A1 * v1 + B1 * v2):", v3_formatado)

    print("\nDigite 'F' para sair ou pressione Enter para continuar...")
    if input().strip().upper() == 'F':
        print("Tecla 'F' pressionada. Saindo...")
        break

print("Programa encerrado.")

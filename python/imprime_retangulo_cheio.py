largura = int(input("Digite a largura: "))
altura = int(input("Digite a altura: "))

for i in range(altura):
    for j in range(largura):
        print('#', end='')
    print()  # Adiciona uma quebra de linha ao final de cada linha
# Exercício 2 - Primos
def ehPrimo(k):
    if k < 2:
        return False
    for i in range(2, int(k ** 0.5) + 1):
        if k % i == 0:
            return False
    return True

def maior_primo(n):
    for i in range(n, 1, -1):
        if ehPrimo(i):
            return i

def remove_repetidos(lista):
    """
    Remove elementos repetidos de uma lista e a retorna ordenada.
    """
    lista_sem_repeticao = list(set(lista))
    lista_sem_repeticao.sort()
    return lista_sem_repeticao

# Exemplo de uso:
lista1 = [2, 4, 2, 2, 3, 3, 1]
print(remove_repetidos(lista1))  # Saída: [1, 2, 3, 4]

lista2 = [1, 2, 3, 3, 3, 4]
print(remove_repetidos(lista2))  # Saída: [1, 2, 3, 4]
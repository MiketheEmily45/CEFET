import random
from collections import Counter

# Criar uma lista com 20 números inteiros aleatórios entre 1 e 10
lista = [random.randint(1, 10) for _ in range(20)]

# Contar as ocorrências de cada número
contagem = Counter(lista)

# Exibir o número de vezes que cada número ocorre
for numero in sorted(contagem.keys()):
    print(f"O número {numero} ocorre {contagem[numero]} vezes")

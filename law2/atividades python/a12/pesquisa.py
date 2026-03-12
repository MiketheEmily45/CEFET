import random

lista = [random.randint(1, 100) for _ in range(50)]

numero = int(input("Informe um número: "))

posicoes = [i for i, x in enumerate(lista) if x == numero]

if posicoes:
    print(f"O número {numero} foi encontrado nas posições: {posicoes}")
else:
    print("Valor não encontrado")

print("Lista gerada:")
print(lista)

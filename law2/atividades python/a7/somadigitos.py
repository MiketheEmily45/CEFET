numero = int(input("Digite um número: "))

soma = 0
for digito in str(numero):
    soma += int(digito)
print(f"A soma dos dígitos de {numero} é {soma}.")
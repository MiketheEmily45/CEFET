print("1 Saudação Personalizada\n")

nome = input("Digite seu nome: ")
print("Olá,", nome, "! Seja bem vindo(a).")

print("\n2 Cadastro simples\n")

nome = input("Digite seu nome: ")
idade = int(input("Digite sua idade: "))
cidade = input("Digite sua cidade: ")
print("Olá,", nome, "! Você tem", idade, "anos e mora em", cidade + ".")    

print("\n3 Etiqueta de endereço\n")

nome = input("Digite seu nome completo: ")
endereço = input("Digite seu endereço: ")
telefone = int(input("Digite seu telefone: "))
print("Ola,\n", nome, "\n", endereço, "\n", telefone)

print("\n4 União de palavras\n")

nome1 = input("Digite uma palavra:")
nome2 = input("Digite outra palavra:")
print(nome1.upper() + nome2.upper())

print("\n5 Conversão de medidas\n")

medida = int(input("Digite uma medida em metros: "))
print("A medida em cm é : ", medida * 100, ", e em mm é: ", medida * 1000, ".")

print("\n6 Cálculo simples\n")

numero = float(input("Digite um número"))
print("O dobro do número é: ", numero * 2, "e o terço é: ", numero / 3, ".")

print("\n7  Calculadora de Quatro Operações:\n")

num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))

print("Soma:", num1 + num2)
print("Subtração:", num1 - num2)
print("Multiplicação:", num1 * num2)
print("Divisão:", num1 / num2)

print("\n8 Cálculo de Média Escolar\n")

num1 = float(input("Digite a primeira nota: "))
num2 = float(input("Digite a segunda nota: "))
num3 = float(input("Digite a terceira nota: "))

print("A média é:", (num1 + num2 + num3) / 3)

print("\n9 Cálculo de Área:\n")

num1 = float(input("Digite a largura: "))
num2 = float(input("Digite o comprimento: "))
print("A área do retângulo é:", num1 * num2)

print("\n10  Calculadora de Números Decimais\n")

num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))

print("Soma:", num1 + num2)
print("Subtração:", num1 - num2)
print("Multiplicação:", num1 * num2)
print("Divisão:", num1 / num2)

print("\n11 salario minimo\n")

salario = float(input("Digite o valor do salário mínimo: "))
reajuste = float(input("Digite o percentual de reajuste: "))
print("O novo salário é:", salario * (1 + reajuste / 100))

print("\n12 IMC\n")

peso = float(input("Digite seu peso em kg: "))
altura = float(input("Digite sua altura em metros: "))
print("Seu IMC é:", peso / (altura ** 2))
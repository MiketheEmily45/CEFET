print("Lista de Exercícios de Python");

print("\n\n1. Saudação Personalizada:\n"); #Peça o nome do usuário e mostre a mensagem: Olá, [nome]! Bem-vindo(a)!.

print("Digite seu nome:");
nome = input("Nome: ");
print("\nOlá," + nome + "! Bem-Vindo(a)!");

print("\n\n2. Cadastro Simples: "); #Solicite o nome, a idade e a cidade do usuário. Ao final, exiba a frase: Seu nome é [nome], você tem [idade] anos e mora em [cidade].

print("Digite seu nome completo:");
nome = input("Nome completo: ");
idade=input("Digite sua idade: ");
cidade=input("Digite sua cidade: ");
print("\nSeu nome é " + nome + ",você tem " + idade + " anos e mora em " + cidade);

print("\n\n3. Etiqueta de Endereço:\n"); # Escreva um programa que imprima seu nome completo, endereço e telefone, cada informação em uma linha separada.\n");

endereco = input("Digite seu endereco: ");
tel= input("Digite seu telefone: ");

print("\nNome: " + nome );
print("Endereco: " + endereco);
print("Telefone: " + tel);

print("\n\n4. União de Palavras:\n"); # Peça ao usuário para digitar duas palavras. Junte-as em uma única frase e depois mostre a frase inteira em letras maiúsculas.\n");

pal1= input("Digite a 1° palavra: ");
pal2= input("Digite a 2° palavra: ");

palavra = pal1.upper()+pal2.upper();

print("\n" + palavra);

print("\n\n5. Conversor de Medidas:\n"); #Leia um valor em metros e o converta para centímetros e milímetros.\n");

tam= float(input("Digite um numero em metros: "));
tam_cm = tam * 100;
tam_mm = tam * 1000;
print("\nTamanho convertido em cm: " + str(tam_cm) + "\nTamanho em mm: " + str(tam_mm));

print("\n\n6. Cálculos Simples:\n"); #Leia um número inteiro e mostre o dobro e a terça parte dele.\n");

num = int(input("Digite um numero inteiro: "));
num_do = num * 2;
num_ter = num / 3;

print("\nO dobro do numero e " + str(num_do) + " e a terca parte do numero e "+str(num_ter));

print("\n\n7. Calculadora de Quatro Operações:\n"); #Peça dois números e mostre os resultados da soma, subtração, multiplicação e divisão entre eles.\n");

a = float(input("Digite o 1° numero para as operações: "));
b = float(input("Digite o 2° numero para as operações: "));

soma = a + b;
sub = a - b;
mult = a * b;
div = a // b;

print("\nSoma: " + str(soma));
print("Subtração: " + str(sub));
print("Multiplicação: " + str(mult));
print("Divisão: " + str(div));

print("\n\n8. Cálculo de Média Escolar:\n"); #Leia três notas de um aluno e calcule a sua média final\n");

n1 = float(input("Digite a 1° nota: "));
n2 = float(input("Digite a 2° nota: "));
n3 = float(input("Digite a 3° nota: "));

media = (n1 + n2 + n3) / 3;

print("\nA media do aluno e : " + str(media));

print("\n\n9. Cálculo de Área:\n"); #Peça a base e a altura de um retângulo e calcule sua área.\n");

al = float(input("Digite o valor da altura: "));
ba = float(input("Digite o valor da base: "));

area = al * ba;

print("\nA area e : "+ str(area));

print("\n\n10. Calculadora de Números Decimais:\n"); #Crie uma calculadora que aceite números com casas decimais (float) para as quatro operações básicas.\n");

a = float(input("Digite o 1° numero para as operações: "));
b = float(input("Digite o 2° numero para as operações: "));

soma = a + b;
sub = a - b;
mult = a * b;
div = a / b;

print("\nSoma: " + str(soma));
print("Subtração: " + str(sub));
print("Multiplicação: " + str(mult));
print("Divisão: " + str(div));

print("\n\n11. Reajuste Salarial:\n"); #Leia o salário de um funcionário e a porcentagem de reajuste. Calcule e mostre o novo salário.\n");

sa = float(input("Digite o salario: "));
re = int(input("Digite a taxa de porcentagem (sendo um valor natural): "));

por = float(re / 100);

reajuste = sa * por;
sal_novo = sa + reajuste;

print("\nO valor do salrio reajustado e : " + str(sal_novo));

print("\n\n12. Índice de Massa Corporal (IMC):\n"); #Peça o peso (kg) e a altura (m) de uma pessoa e calcule o seu IMC.(Fórmula: IMC = Peso/altura²\n");

pe = float(input("Digite seu peso: "));
al = float(input("Digite sua altura: "));

IMC = pe / (al * al);

print("\nSeu IMC e : " + str("{:.2f}".format(IMC)));

print("\nDê enter para sair...");
input();
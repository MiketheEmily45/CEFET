print("Bem-vindo!\nEscolha:\n(1) área retângulo\n(2) volume esfera");
opcao = int(input("opção:"));

if opcao == 1:
    largura = float(input("largura:"));
    altura = float(input("altura:"));
    area = largura * altura;
    print(f"área: {area:.2f}");
elif opcao == 2:
    raio = float(input("raio:"));
    volume = (4/3) * 3.14159 * (raio ** 3);
    print(f"volume: {volume:.2f}");
else:
    print("opção inválida");

print("Dê enter para sair...");
input();
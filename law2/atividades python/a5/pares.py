a = int(input("Digite um número a: "))
b = int(input("Digite um número b: "))
while b <= a:
    print("O número b deve ser maior que a. Digite novamente.")
    b = int(input("Digite um número b: "))
z = int(input("Digite um número z: "))
while z <= b:
    print("O número z deve ser maior que b. Digite novamente.")
    z = int(input("Digite um número z: "))
x = z / 2
y = (z / 2) + (z % 1)

if x == y:
    x += 1
    y -= 1

#Verificar se x e y estão entre a e b, e se a soma de x e y é igual a z

if x > a and x < b and y > a and y < b:
    if x + y == z:
        print("x:", x)
        print("y:", y)
    else:
        print("A soma de x e y não é igual a z.")
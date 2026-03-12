def media (*notas):
    if len(notas) == 0:
        return 0
    return sum(notas) / len(notas)

n1 = float(input("Digite a primeira nota: "))
n2 = float(input("Digite a segunda nota: "))
n3 = float(input("Digite a terceira nota: "))

print("A média é:", media(n1, n2, n3))
if media(n1, n2, n3) >= 6:
    print("Aprovado!")
elif media(n1, n2, n3) >= 4 and media(n1, n2, n3) < 6:
    print("Recuperação!")
else:    
    print("Reprovado!")

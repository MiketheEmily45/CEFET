popA = int(input("Informe a população da cidade A: "))
taxA = float(input("Informe a taxa de crescimento da cidade A (%): "))

popB = int(input("Informe a população da cidade B: "))
taxB = float(input("Informe a taxa de crescimento da cidade B (%): "))

if popA >= popB:
    print("Erro: A população da cidade A deve ser menor que a da cidade B.")
elif taxA <= taxB:
    print("Erro: A taxa de crescimento da cidade A deve ser maior que a da cidade B.")
else:
    anos = 0
    while popA <= popB:
        popA += int(popA * taxA / 100)
        popB += int(popB * taxB / 100)
        anos += 1
        if anos > 100:
            print("Mais de 1 século")
            break
    else:
        print(f"A população da cidade A ultrapassará a da cidade B em {anos} anos.")

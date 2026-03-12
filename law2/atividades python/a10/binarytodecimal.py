def binary_to_decimal(binary):
    decimal = 0
    power = 0
    for digit in reversed(binary):
        if digit == '1':
            decimal += 2 ** power
        power += 1
    return decimal

binary = input("Informe um número em base binária: ")
decimal = binary_to_decimal(binary)
print(f"O valor em decimal é: {decimal}")

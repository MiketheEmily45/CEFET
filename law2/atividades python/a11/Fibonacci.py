def fibonacci(n):
    sequence = []
    a, b = 0, 1
    for _ in range(n):
        sequence.append(a)
        a, b = b, a + b
    return sequence

fibonacci_n = int(input("Digite o número de termos da sequência de Fibonacci: "))
if fibonacci_n < 0:
    print("Erro: O número de termos deve ser um inteiro não negativo.")
else:
    print(f"A sequência de Fibonacci até o {fibonacci_n}-ésimo termo é: {fibonacci(fibonacci_n)}")
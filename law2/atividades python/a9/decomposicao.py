def decomporemprimos(n):
    fatores = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            fatores.append(d)
            n //= d
        d += 1
    if n > 1:
        fatores.append(n)
    return fatores

n = int(input("Digite um número inteiro(maior que 100 e menor que 10000): "))
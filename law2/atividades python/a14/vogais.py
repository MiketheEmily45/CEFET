def contar_vogais():
    texto = contar_vogais.__doc__
    vogais = 'aeiouAEIOU'
    contador = 0
    for char in texto:
        if char in vogais:
            contador += 1
    return contador

quantidade = contar_vogais()
print(f"A quantidade de vogais no texto é: {quantidade}")

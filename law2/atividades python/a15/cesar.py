def cifra_cesar(texto, chave):
    alfabeto_minusculo = 'abcdefghijklmnopqrstuvwxyz'
    alfabeto_maiusculo = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    resultado = ''

    for char in texto:
        if char in alfabeto_minusculo:
            indice = alfabeto_minusculo.index(char)
            novo_indice = (indice + chave) % 26
            resultado += alfabeto_minusculo[novo_indice]
        elif char in alfabeto_maiusculo:
            indice = alfabeto_maiusculo.index(char)
            novo_indice = (indice + chave) % 26
            resultado += alfabeto_maiusculo[novo_indice]
        else:
            resultado += char

    return resultado

texto = input("Informe a string para codificar: ")
chave = int(input("Informe a chave (número de passos): "))

texto_codificado = cifra_cesar(texto, chave)
print(f"Texto codificado: {texto_codificado}")

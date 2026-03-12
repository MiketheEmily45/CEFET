import random

estados_capitais = {
    "Acre": "Rio Branco",
    "Alagoas": "Maceió",
    "Amapá": "Macapá",
    "Amazonas": "Manaus",
    "Bahia": "Salvador",
    "Ceará": "Fortaleza",
    "Distrito Federal": "Brasília",
    "Espírito Santo": "Vitória",
    "Goiás": "Goiânia",
    "Maranhão": "São Luís",
    "Mato Grosso": "Cuiabá",
    "Mato Grosso do Sul": "Campo Grande",
    "Minas Gerais": "Belo Horizonte",
    "Pará": "Belém",
    "Paraíba": "João Pessoa",
    "Paraná": "Curitiba",
    "Pernambuco": "Recife",
    "Piauí": "Teresina",
    "Rio de Janeiro": "Rio de Janeiro",
    "Rio Grande do Norte": "Natal",
    "Rio Grande do Sul": "Porto Alegre",
    "Rondônia": "Porto Velho",
    "Roraima": "Boa Vista",
    "Santa Catarina": "Florianópolis",
    "São Paulo": "São Paulo",
    "Sergipe": "Aracaju",
    "Tocantins": "Palmas"
}

estados = list(estados_capitais.keys())
random.shuffle(estados)

acertos = 0
total_perguntas = 0

for estado in estados:
    resposta = input(f"Qual a capital do estado {estado}? ").strip()
    capital_correta = estados_capitais[estado]
    
    if resposta.lower() == capital_correta.lower():
        print("Correto!")
        acertos += 1
    else:
        print(f"Incorreto. A capital é {capital_correta}.")
    
    total_perguntas += 1
    
    continuar = input("Deseja continuar? (s/n): ").strip().lower()
    if continuar != 's':
        break

porcentagem = (acertos / total_perguntas) * 100 if total_perguntas > 0 else 0

print(f"\nVocê acertou {acertos} de {total_perguntas} perguntas.")
print(f"Porcentagem de acertos: {porcentagem:.2f}%")

gols1 = int(input("Insira o número de gols do primeiro time: "))
gols2 = int(input("Insira o número de gols do segundo time: "))
if gols1 > gols2:
    resul = 1
elif gols1 < gols2:
    resul = 2
else:
    resul = 0


gols1prev = int(input("Insira o número previsto de gols do primeiro time: "))
gols2prev = int(input("Insira o número previsto de gols do segundo time: "))

pontos = 0

if gols1prev > gols2prev and resul == 1:
    pontos += 10
elif gols1prev < gols2prev and resul == 2:
    pontos += 10
elif gols1prev == gols2prev and resul == 0:
    pontos += 10

if gols1prev == gols1:
    pontos += 5
if gols2prev == gols2:
    pontos += 5

print("Você fez", pontos, "pontos!")
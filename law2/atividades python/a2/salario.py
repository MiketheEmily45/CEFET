ganho = float(input("Insira o quanto ganha em hora: "))
horas = float(input("Insira quantas horas trabalha por semana: "))

salario = 0

if horas > 60:
    salario += (horas - 60) * ganho * 2
    horas = 60
if horas > 40:
    salario += (horas - 40) * ganho * 1.5
    horas = 40
if horas > 0:
    salario += horas * ganho
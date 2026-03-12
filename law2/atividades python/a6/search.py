def search(arr, target):
    found = 0
    for i in range(len(arr)):
        if arr[i] == target:
            found += 1
    return found

big_number = int(input("Digite um número: "))
find = int(input("Digite um número para procurar: "))

result = search(list(range(1, big_number + 1)), find)
print(f"O número {find} aparece {result} vezes na lista.")
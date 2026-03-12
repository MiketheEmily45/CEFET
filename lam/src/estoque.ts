function checarestoque (nome: string, estoqueminimo: number, quantidade: number): string {
    if (quantidade < estoqueminimo) {
        return `O estoque do produto ${nome} está abaixo do mínimo. Estoque atual: ${quantidade}.`
    } else {
        return `O estoque do produto ${nome} está dentro do limite. Estoque atual: ${quantidade}.`
    }
}

console.log(checarestoque("Caneta", 10, 5))
console.log(checarestoque("Lápis", 20, 25))
function pesquisar (email: string, lista: string[]): boolean {
    for (let i = 0; i < lista.length; i++) {
        if (lista[i] === email) {
            return true
        }
    }
    return false
}
console.log(pesquisar("joao@example.com", ["maria@example.com", "joao@example.com", "pedro@example.com"]))
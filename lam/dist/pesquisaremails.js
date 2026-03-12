"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function pesquisar(email, lista) {
    for (let i = 0; i < lista.length; i++) {
        if (lista[i] === email) {
            return true;
        }
    }
    return false;
}
console.log(pesquisar("joao@example.com", ["maria@example.com", "joao@example.com", "pedro@example.com"]));
//# sourceMappingURL=pesquisaremails.js.map
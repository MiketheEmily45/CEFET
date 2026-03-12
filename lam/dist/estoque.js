"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function checarestoque(nome, estoqueminimo, quantidade) {
    if (quantidade < estoqueminimo) {
        return `O estoque do produto ${nome} está abaixo do mínimo. Estoque atual: ${quantidade}.`;
    }
    else {
        return `O estoque do produto ${nome} está dentro do limite. Estoque atual: ${quantidade}.`;
    }
}
console.log(checarestoque("Caneta", 10, 5));
console.log(checarestoque("Lápis", 20, 25));
//# sourceMappingURL=estoque.js.map
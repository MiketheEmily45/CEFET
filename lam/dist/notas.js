"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function analisar_situação(nome, nota, nota2) {
    let media = (nota + nota2) / 2;
    if (media >= 6) {
        return `Parabéns ${nome}! Você foi aprovado com média ${media.toFixed(2)}.`;
    }
    else {
        return `Olá ${nome}, infelizmente você foi reprovado com média ${media.toFixed(2)}.`;
    }
}
console.log(analisar_situação("João", 7, 8));
//# sourceMappingURL=notas.js.map
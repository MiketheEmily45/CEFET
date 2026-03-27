"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function ehpar(numero) {
    return numero % 2 === 0;
}
for (let i = 1; i <= 10; i++) {
    if (ehpar(i)) {
        console.log(`${i} é par.`);
    }
    else {
        console.log(`${i} é ímpar.`);
    }
}
//# sourceMappingURL=paridadade.js.map
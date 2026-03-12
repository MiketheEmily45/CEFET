function desconto(preço: number, tipodeconto: string): string {
    let valorfinal: number;

    if (tipodeconto === "COMUM") {
        valorfinal = preço * 0.95; // Desconto de 5%
        return `Cliente COMUM - Valor final: R$ ${valorfinal.toFixed(2)}`;
    } else if (tipodeconto === "VIP") {
        valorfinal = preço * 0.85; // Desconto de 15%
        return `Cliente VIP - Valor final: R$ ${valorfinal.toFixed(2)}`;
    } else if (tipodeconto === "PREMIUM") {
        valorfinal = preço * 0.75; // Desconto de 25%
        return `Cliente PREMIUM - Valor final: R$ ${valorfinal.toFixed(2)}`;
    } else {
        return "Tipo de desconto inválido";
    }
}

console.log(desconto(100, "COMUM"));
console.log(desconto(100, "VIP"));
console.log(desconto(100, "PREMIUM"));
console.log(desconto(100, "OUTRO"));
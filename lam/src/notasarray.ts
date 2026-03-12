function notasArray(notas: number[]): string {
    let soma = 0;
    let media = 0;
    for (let i = 0; i < notas.length; i++) {
        soma += notas[i];
    }
    media = soma / notas.length;
    return `A média das notas é (arredondada) ${media.toFixed(2)} ou ${media}.`;
}

console.log(notasArray([7, 8, 9, 10]));
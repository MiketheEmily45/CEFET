#include <stdio.h>
#include <stdlib.h>

int main() {
    float valorProduto, valorComDesconto, valorFinal, valorParcela;
    int opcaoGarantia;

    // Solicita o valor do produto e se o cliente deseja garantia estendida
    printf("Digite o valor do produto: ");
    scanf("%f", &valorProduto);
    printf("Deseja adquirir garantia estendida? (0 - Não, 1 - Sim): ");
    scanf("%d", &opcaoGarantia);

    // Calcula o valor com ágio de garantia, se aplicável
    if (opcaoGarantia == 1) {
        valorProduto = valorProduto * 1.75; // Ágio de 75%
    }

    // Exibe as opções de pagamento
    printf("Opções de pagamento:\n");

    // À vista com 30% de desconto
    valorComDesconto = valorProduto * 0.70;
    printf("À vista com 30%% de desconto: R$%.2f\n", valorComDesconto);

    // Parcelado em 3 vezes com 15% de desconto
    valorComDesconto = valorProduto * 0.85;
    valorParcela = valorComDesconto / 3;
    printf("Parcelado em 3 vezes com 15%% de desconto (R$%.2f cada parcela): R$%.2f\n", valorParcela, valorComDesconto);

    // Parcelado em 6 vezes sem desconto
    valorParcela = valorProduto / 6;
    printf("Parcelado em 6 vezes sem desconto (R$%.2f cada parcela): R$%.2f\n", valorParcela, valorProduto);

    return 0;
}

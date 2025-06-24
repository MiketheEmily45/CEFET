#include <stdio.h>
#include <stdbool.h>

bool primo(int pri, int divisor) {
    if (pri <= 1) {
        return false;
    }
    if (divisor == 1) {
        return true;
    }
    if (pri % divisor == 0) {
        return false;
    }
    return primo(pri, divisor - 1);
}

int main() {
    int n;
    printf("Insira um número natural:\n");
    scanf("%d", &n);
    
    if (primo(n, n - 1)) {
        printf("%d é primo\n", n);
    } else {
        printf("%d não é primo\n", n);
    }

    return 0;
}
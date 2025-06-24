#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ordem[20];
    ordem[0] = 0;
    ordem[1]= 1;
    for(int i = 2; i <= 19; i++){
        ordem[i] = ordem[i - 1] + ordem[i - 2];
    }
    for(int i = 0; i <= 19; i++){
        printf("%d ", ordem[i]);
    }
    return 0;
}
#include <cstdio>
#include "random_generate.h"
#include "game.h"

int main() {
    int max_limit = 20, min_limit = 1;
    char ans;
    do{
        system("cls");
        graj(min_limit, max_limit);
        printf("Czy chcesz zagrac jeszcze raz? (T/N)");
        scanf(" %c",&ans);
    }while(ans =='T' || ans =='t');

    /* konwertowanie liczb  */
    int decimal;
    printf("\n\n\n\nLiczbe w decymalnym systemie");
    scanf(" %d", &decimal);
    printf("Liczba w hex: %X\n", decimal);

    return 0;
}

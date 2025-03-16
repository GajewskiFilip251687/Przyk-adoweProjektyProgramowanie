//
// Created by student on 09.03.2025.
//

#ifndef INC_255934_GAME_H
#define INC_255934_GAME_H

#endif //INC_255934_GAME_H
#include <cstdio>
void graj(int &start, int &stop){
    printf("\n### Gra polega na odgadnieciu liczby wylosowanej przez komputer. ###\n\n");

    int userNum, counter = 0, rand_value;
    rand_value = generateRandNum(start, stop);

    printf("Wylosowana liczba bedzie z zakresu %d-%d.\n",start, stop);

    printf("Podaj swoja liczbe:");
    scanf("%d",&userNum);

    while(userNum != rand_value){
        counter+=1;
        if (userNum > rand_value)
            printf("Twoja liczba jest za duza!. Sprobuj jeszcze raz!");
        else
            printf("Twoja liczba jest za mala!. Sprobuj jeszcze raz!");

        scanf("%d",&userNum);
    }
    printf("--- Brawo wygrales w %d probach! ---\n\n", counter+1);
}
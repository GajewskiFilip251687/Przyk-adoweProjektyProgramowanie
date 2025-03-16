//
// Created by student on 09.03.2025.
//

#ifndef INC_255934_RANDOM_GENERATE_H
#define INC_255934_RANDOM_GENERATE_H

#endif //INC_255934_RANDOM_GENERATE_H
#include <ctime>
#include <cstdlib>

int generateRandNum(int max, int min){
    int randomNum;
    time_t t;
    srand(time(&t));
    randomNum = rand()%(max-min+1) +1;
    return randomNum;
}

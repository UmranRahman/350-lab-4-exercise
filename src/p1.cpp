#include <iostream>
#include <list>
#include <random>
#include "timer.h"

constexpr size_t ARRAY_2D = 4000;

int main() { 
    //Row-major-order
    static uint64_t rm_array[ARRAY_2D][ARRAY_2D];
    static uint64_t cm_array[ARRAY_2D][ARRAY_2D];
    uint64_t rm_sum = 0;
    uint64_t cm_sum = 0;
    std::mt19937_64 rng(0);

    for (size_t i = 0; i < ARRAY_2D; i++){
        for (size_t j = 0; j < ARRAY_2D; j++) {
            rm_array[i][j] = rng();
            cm_array[j][i] = rm_array[i][j];
        }
    }

    Timer t;
    //Row-major-order
    for (size_t i = 0; i < ARRAY_2D; i++){
        for (size_t j = 0; j < ARRAY_2D; j++) {
            rm_sum += rm_array[i][j];
        }
    }
    uint64_t elapsed = t.click<Timer::Micros>();
    std::cout << elapsed << " "  << rm_sum <<"\n";

    //Column-major-order
    for (size_t j = 0; j < ARRAY_2D; j++){
        for (size_t i = 0; i < ARRAY_2D; i++) {
            cm_sum += cm_array[i][j];
        }
    }
    uint64_t elapsed2 = t.click<Timer::Micros>();
    std::cout << elapsed2 << " " << cm_sum <<"\n";

    return 0;
}

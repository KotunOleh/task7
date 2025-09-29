#include "randomcontroller.h"

RandomController::RandomController(long long N)
    : engine(std::random_device{}()), 
    distribution(0, N - 1) {
}

Cell RandomController::operator()() {
    long long x = distribution(engine);
    long long y = distribution(engine);
    return {x, y};
}
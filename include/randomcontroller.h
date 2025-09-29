#pragma once

#include <random>
#include "cell.h"

class RandomController {
private:
    std::mt19937 engine;
    std::uniform_int_distribution<long long> distribution;

public:
    RandomController(long long N);
    Cell operator()();
};
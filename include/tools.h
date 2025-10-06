#pragma once

#include <map>
#include <string>
#include "cell.h"

long long inputInt();
double averageFrequency(const std::map<Cell, long long>& map, const long long sum);
double expectedFrequency(const long long sum, const long long N);
double standartDeviation(const std::map<Cell, long long>& map, const double expected_freq);
double deviationPercent(const double expected_freq, const double standart_dev);
double medianFrequency(const std::map<Cell, long long>& map);
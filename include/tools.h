#pragma once

#include <map>
#include <string>
#include "cell.h"

long long inputInt();
void displayCellFrequencies(const std::map<Cell, long long>& map);
double average(const std::map<Cell, long long>& map, const long long sum);
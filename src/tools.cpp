#include "tools.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

long long inputInt() {
    long long a;
    std::cin >> a;
    if (std::cin.fail()) {
        throw std::runtime_error("\nYou entered something that is NOT an integer!");
    }
    return a;
}

void displayCellFrequencies(const std::map<Cell, long long>& map) {
    std::cout << "\n ### Frequency of each cell ###\n";
    for (const auto& pair : map) {
        std::cout << "Cell [" << pair.first.x << " " << pair.first.y << "]: " << pair.second << " times\n";
    }
}

double averageFrequency(const std::map<Cell, long long>& map, const long long sum) {
    if (map.empty()) {
        return 0.0;
    }
    return static_cast<double>(sum) / map.size();
}

double medianFrequency(const std::map<Cell, long long>& map) {
    if (map.empty()) {
        return 0.0;
    }

    std::vector<long long> frequencies;
    frequencies.reserve(map.size());
    for (const auto& pair : map) {
        frequencies.push_back(pair.second);
    }

    std::sort(frequencies.begin(), frequencies.end());

    size_t n = frequencies.size();
    size_t mid_index = n / 2;

    if (n % 2 != 0) {
        return static_cast<double>(frequencies[mid_index]);
    } else {
        return (static_cast<double>(frequencies[mid_index - 1]) + frequencies[mid_index]) / 2.0;
    }
}
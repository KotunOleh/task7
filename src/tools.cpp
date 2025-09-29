#include "tools.h"
#include <iostream>
#include <stdexcept>

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

double average(const std::map<Cell, long long>& map, const long long sum) {
    if (map.empty()) {
        return 0.0;
    }
    return static_cast<double>(sum) / map.size();
}
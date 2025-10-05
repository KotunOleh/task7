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

double expectedFrequency(const long long sum, const long long N) {
    if (N <= 0 || sum <= 0) {
        std::cout << "\nNot enough data for analysis";
        return 0.0;
    }
    return static_cast<double>(sum) / (N * N);
}

double standartDeviation(const std::map<Cell, long long>& map, const double expected_freq) {
    std::vector<long long> frequencies;
    frequencies.reserve(map.size());
    for (const auto& pair : map) {
        frequencies.push_back(pair.second);
    }

    double diff_sum = 0.0;
    for (long long freq : frequencies) {
        double diff = freq - expected_freq;
        diff_sum += diff * diff;
    }
    double variance = diff_sum / frequencies.size();
    return std::sqrt(variance);
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
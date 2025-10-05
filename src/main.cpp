#include <iostream>
#include <stdexcept>
#include <limits>
#include <map>

#include "cell.h"
#include "randomcontroller.h"
#include "tools.h"

int main() {
    try {
        long long N;
        long long m;

        std::cout << "Enter the size of the square's (N x N) side: ";
        N = inputInt();
        if (N <= 0) throw std::domain_error("\nEntered number must be greater than 0!");

        std::cout << "Enter the amount of cells that you want to pick from the board (m): ";
        m = inputInt();
        if (m <= 0) throw std::domain_error("\nEntered number must be greater than 0!");

        RandomController controller(N);
        std::map<Cell, long long> freqMap;

        for (long long i = 0; i < m; i++) {
            freqMap[controller()]++;
        }

        displayCellFrequencies(freqMap);
        double avg_freq = averageFrequency(freqMap, m);
        std::cout << "\nAverage frequency is " << avg_freq;

        double med_freq = medianFrequency(freqMap);
        std::cout << "\nMeadian frequency is " << med_freq;

        double exp_freq = expectedFrequency(m, N);
        std::cout << "\nExpected frequency per cell according to amount of picked cells is " << exp_freq;

        double stand_dev = standartDeviation(freqMap, exp_freq);
        std::cout << "\nstandart deviation is " << stand_dev;



    } catch (const std::exception& e) {
        std::cerr << "\n***** error: " << e.what();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
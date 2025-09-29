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
        std::cout << "\nAverage frequency is " << average(freqMap, m);

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
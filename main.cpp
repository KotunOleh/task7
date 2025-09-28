// The authors of this program are Oleh Kotun and Oles Legkiy

#include <iostream>
#include <vector>
#include <random>
#include <string> 
#include <map> 

struct Cell{
	long long x;
	long long y;

	bool operator<(const Cell& other) const {
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
};
long long inputInt() {
	long long a;
	std::cin >> a;
	if (std::cin.fail()) throw std::runtime_error("\nYou entered something that is NOT integer!");
	return a;
}

void displayCellFrequencies(const std::map<Cell, long long>& map) {
  std::cout << "\n ### Frequency of each cell ###\n";
    for (const auto& pair : map) {
        std::cout << "Cell [" << pair.first.x << " " << pair.first.y << "]: " << pair.second << " times\n";
      }
}

double average(const std::map<Cell, long long>& map, const  long long sum) {
	if (map.empty()) return 0.0;
  	return static_cast<double>(sum) / map.size();
}


class RandomController {
private:
  std::mt19937 engine;
  std::uniform_int_distribution<long long> distribution;
public:
  RandomController(long long N) :
    engine(std::random_device{}()),
    distribution(0, N-1){}

  Cell operator()() {
    long long x = distribution(engine);
    long long y = distribution(engine);
    return {x, y};
  }
};

int main() {
	try {
		long long N;
		long long m;

		std::cout << "Enter the size of square`s (N x N) side: ";
		N = inputInt();
		if (N <= 0) throw std::domain_error("\nEntered number must be greater than 0!");

		std::cout << "Enter the amount of cells that you want to pick from board (m): ";
		m = inputInt();
		if (m <= 0) throw std::domain_error("\nEntered number must be greater than 0!");

		RandomController controller(N);

		std::map<Cell, long long> freqMap; 

    	for (long long i = 0; i < m; i++) {
			freqMap[controller()]++;
    	}

		displayCellFrequencies(freqMap);

		std::cout << "\nAverage frequency is " << average(freqMap, m);
	}

	catch (const std::exception& e) {
		std::cerr << "\n***** error";
		std::cerr << e.what();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "\nPress Enter to exit..."; 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	std::cin.get();

	return 0;
}
#include <iostream>
#include <vector>
#include <random>
#include <string> 
#include <map> 

long long inputInt() {
	long long a;
	std::cin >> a;
	if (std::cin.fail()) throw std::runtime_error("\nYou entered something that is NOT integer!");
	return a;
}
void updateMap(std::map<std::string, long long>& map, const std::string& key) {
  	map[key]++;
}

class Cell {
private:
	long long x;
	long long y;
public:
	Cell(long long x_value, long long y_value) :
		x(x_value), y(y_value) {}
	std::string toString() const {
		return std::to_string(x) + " " + std::to_string(y);
	}
};

class RandomController {
private:
  long long boardSide;
  std::random_device r;
  std::mt19937 engine;
  std::uniform_int_distribution<long long> distribution;
public:
  RandomController(long long N) :
    boardSide(N),
    engine(r()),
    distribution(0, N-1){}

  Cell operator()() {
    long long x = distribution(engine);
    long long y = distribution(engine);
    return Cell(x, y);
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

		std::map<std::string, long long> krat_map; 

    	for (long long i = 0; i < m; i++) {
      		updateMap(krat_map, controller().toString());
    	}
	}

	catch (const std::exception& e) {
		std::cerr << "\n***** error";
		std::cerr << e.what();
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	std::cin.get();

	return 0;
}
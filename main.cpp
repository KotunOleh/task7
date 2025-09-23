#include <iostream>
#include <vector>
#include <random>
#include <string> 

long long inputInt() {
	long long a;
	std::cin >> a;
	if (std::cin.fail()) throw std::runtime_error("\nYou entered something that is NOT integer!");
	return a;
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
	RandomController(int N) :
		boardSide(N),
		engine(r()){}

	Cell operator()() {
		std::uniform_int_distribution<long long> dist(0, boardSide - 1);
		long long x = dist(engine);
		long long y = dist(engine);
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
		if (m > N * N) throw std::domain_error("\nYou have to choose number of cells that is less than the whole amount of cells on the board!");


		RandomController controller(N);

		for (long long i = 0; i <= m; i++) {
			std::cout << controller().toString() << "\n";
		}
	}

	catch (const std::exception& e) {
		std::cerr << "\n***** error";
		std::cerr << e.what();
	}
	return 0;
}
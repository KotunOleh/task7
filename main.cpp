#include <iostream>
#include <vector>
#include <random>
#include <string> 

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
};

long long inputInt() {
	long long a;
	std::cin >> a;
	if (std::cin.fail()) throw std::runtime_error("\nYou entered something that is NOT integer!");
	return a;
}


int main() {
	std::cout << "init";
}
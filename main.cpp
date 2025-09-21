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

	Cell operator()() {
		std::uniform_int_distribution<long long> dist(0, boardSide - 1);
		long long x = dist(engine);
		long long y = dist(engine);
		return Cell(x, y);
	}
};



int main() {
	std::cout << "init";
}
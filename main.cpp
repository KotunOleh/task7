#include <iostream>
#include <vector>
#include <random>

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



int main() {
	std::cout << "init";
}
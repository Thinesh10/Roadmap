#include <iostream>

int main() {
	std::cout << "Week 1 | Day 3 | Exercises" << std::endl;
	int i = 0;
	int j(0); // calls constructor like syntax
	int k{0}; // prevents narrowing conversions
	
	std::cout << i << ", " << j << ", " << k << std::endl;

	constexpr int MAX_LINES = 1000;
	constexpr int DEFAULT_BUFFER_SIZE = 100;

	// constexpr evaluates expressions at compile time.
	// constexpr is preffered to #define because it has scope and type checking.  

	return 0;
}

#include <iostream>
#include <vector>

int main() {

	// 1
	std::string name;
	int age;
	double balance;

	std::cin >> name >> age >> balance;
	std::cout << "Name: " << name << ", Age: " << age << ", Balance: " << balance << std::endl;

	// 2
	std::vector<std::string> buffer;
	std::string line;

	for (int i = 0; i < 5; ++i)
	{
		std::cin >> line;
		buffer.emplace_back(line);

	}

	for (const auto& s: buffer)
	{
		std::cout << s << std::endl;
	}

	return 0;
}

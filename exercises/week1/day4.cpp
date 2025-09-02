#include <ranges>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

void value(int val); // copy value, expensive with large objects
void reference(int& val); // doesn't copy value, can modify value
void const_reference(const int& val); // doesn't copy value, cannot modify

std::string reverse_string(const std::string& s)
{
	std::string ret = s;
	std::ranges::reverse(ret);
	return ret;
	
	// consider using std::swap to remove iterator overhead and copying overhead 
	// will swap characters inplace e.g. &s[0] and &s[0] + size - 1 and increment / decrement pointers
	// also cache friendly approach
}

int sum_array(const std::vector<int>& arr)
{
	return std::accumulate(arr.begin(), arr.end(), 0);	
}



int main() {
	std::cout << "Week 1 | Day 4 | Exercises" << std::endl;


	// 2
	std::string s("Example");
	std::cout << "Before: " << s << ", After: " << reverse_string(s) << std::endl; 
	
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "Sum = " << sum_array(v) << std::endl;
	return 0;
}

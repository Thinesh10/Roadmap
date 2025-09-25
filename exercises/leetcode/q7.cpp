#include <cstdlib>
#include <iostream>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        long long result = 0;

        while (x != 0)
        {
            result += x % 10;
            x /= 10;

            if (x != 0)
            {
                result *= 10;
            }
        }

        if ((result > INT_MAX) || (result < INT_MIN))
        {
            return 0;
        } 

        return result;
    }
};

#include <limits>
#include <cctype>
#include <string_view>
#include <charconv>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int myAtoi(string s) {
        std::string_view sv = s;

        auto it = std::ranges::find_if_not(sv, [](unsigned char c)
        { return std::isspace(c); });
        sv.remove_prefix(std::distance(sv.begin(), it));

        int sign = 1;
        if (!sv.empty() && ((sv.front() == '+') || sv.front() == '-'))
        {
            sign = (sv.front() == '-') ? -1 : 1;
            sv.remove_prefix(1);
        }

        if (!std::isdigit(static_cast<unsigned char>(sv.front()))) return 0;

        long long result = 0;
        auto [ptr, e] = std::from_chars(sv.data(), sv.data() + sv.size(), result);

        if (e == std::errc::result_out_of_range)
        {
            return (sign == -1) ? INT_MIN : INT_MAX;
        }

        result = sign * result;

        if (result > INT_MAX)
        {   
            return INT_MAX;
        }
        else if (result < INT_MIN)
        {
            return INT_MIN;
        }

        return static_cast<int>(result);
    }
};

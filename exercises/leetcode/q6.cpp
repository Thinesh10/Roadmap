#include <cmath>
#include <ranges>

class Solution {
public:
    string convert(string s, int numRows) {
        if ((numRows == 1) || (s.size() <= numRows)) return s;

        std::vector<std::string> v(numRows);

        auto currVec = 0, vecOp = 1;

        for (const auto& c: s)
        {
            v[currVec].push_back(c);
            
            if (currVec == 0)
            {
                vecOp = 1;
            }
            else if (currVec == numRows - 1)
            {
                vecOp = -1;
            }

            currVec += vecOp;
        }

        std::string ret;
        for (const auto& st: v)
        {
            ret += st;
        }

        return ret;
    }
};

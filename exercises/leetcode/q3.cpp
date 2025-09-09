#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        std::unordered_map<char, int> m;
        auto longestLength = 0;
        auto startIndex = 0;
        auto length = 0;

        for (auto i = 0; i != s.size(); ++i)
        {
            if (m.find(s[i]) == m.end())
            {
                m.emplace(std::pair<char, int>(s[i], i));
            }
            else
            {
                if (m[s[i]] >= startIndex)
                {
                    startIndex = m[s[i]] + 1;
                }

                m[s[i]] = i;
                length = i - startIndex;
            }

            length += 1;

            if (length > longestLength)
            {
                longestLength = length;
            }
        }

        if (m.size() == s.size())
        {
            return s.size();
        }

        return longestLength;
    }
};

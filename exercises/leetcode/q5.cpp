class Solution {
public:
    string longestPalindrome(string s) {
       
        auto table = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size()));
        auto maxlen = 0, start = 0;
        for (auto i = 0; i < s.size(); ++i)
        {
            table[i][i] = 1;
        }

        maxlen = 1;

        // 2
        for (auto i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == s[i+1])
            {
                table[i][i+1] = 1;
                start = i;
                maxlen = 2;
            }
        }

        // 3 or longer
        for (auto len = 2; len < s.size(); ++len)
        {
            for (auto i = 0; i < s.size() - len; ++i)
            {
                if ((s[i] == s[i+len]) && (table[i+1][i+len-1] == 1))
                {
                    table[i][i+len] = 1;
                    if (len + 1 > maxlen)
                    {
                        maxlen = len + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};

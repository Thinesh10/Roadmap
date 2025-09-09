#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;

        for (auto i = 0; i < nums.size(); ++i)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                return {m[target - nums[i]], i};
            }

            m.emplace(std::pair<int, int>(nums[i], i));
        }

        return {};
    }
};

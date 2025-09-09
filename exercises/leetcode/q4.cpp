class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto totalSize = nums1.size() + nums2.size();
        std::vector<int> medianIndices;
        
        if (totalSize % 2 == 0)
        {
            medianIndices.emplace_back((totalSize / 2) - 1);
            medianIndices.emplace_back(totalSize / 2);
        }
        else
        {
            medianIndices.emplace_back((totalSize - 1) / 2);
        }
        
        std::vector<int> merged;
        merged.resize(nums1.size() + nums2.size());
        const auto result = std::ranges::merge(nums1, nums2, merged.begin());

        if (medianIndices.size() == 2)
        {
            return (merged[medianIndices[0]] + merged[medianIndices[1]]) / 2.0; 
        }
        else
        {
            return merged[medianIndices[0]];
        }
    }
};

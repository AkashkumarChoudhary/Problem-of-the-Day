class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int ones = std::accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        if (ones == 0) {
            return 0;
        }
        
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        int windowSum = std::accumulate(nums.begin(), nums.begin() + ones, 0);
        int maxOnes = windowSum;
        int swaps = ones - maxOnes;
        
        for (int i = 1; i < n; ++i) {
            windowSum += nums[i + ones - 1] - nums[i - 1];
            maxOnes = std::max(maxOnes, windowSum);
            swaps = std::min(swaps, ones - maxOnes);
        }
        
        return swaps;
    }
};

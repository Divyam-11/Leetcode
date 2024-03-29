#include <vector>
#include <algorithm>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        int max_element = *std::max_element(nums.begin(), nums.end());
        long long result = 0;
        int high = 0;
        int max_freq = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (max_freq < k && high < nums.size()) {
                if (nums[high] == max_element) max_freq++;
                high++;
            }
            if(max_freq == k)
            result += nums.size() - high + 1; // Count subarrays from current position to end
            if (nums[i] == max_element) max_freq--;
        }
        return result;
    }
};

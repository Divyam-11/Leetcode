#include <vector>
#include <cmath>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // Step 1: Mark negative numbers and zeros as non-existent
        for(int i = 0; i < n; ++i) {
            if(nums[i] <= 0)
                nums[i] = n + 1;
        }

        // Step 2: Mark visited indices by negating the value at the corresponding index
        for(int i = 0; i < n; ++i) {
            int val = std::abs(nums[i]);
            if(val <= n && nums[val - 1] > 0)
                nums[val - 1] *= -1;
        }

        // Step 3: Find the first missing positive integer
        for(int i = 0; i < n; ++i) {
            if(nums[i] > 0)
                return i + 1;
        }

        // If all positive integers from 1 to n are present, return n + 1
        return n + 1;
    }
};

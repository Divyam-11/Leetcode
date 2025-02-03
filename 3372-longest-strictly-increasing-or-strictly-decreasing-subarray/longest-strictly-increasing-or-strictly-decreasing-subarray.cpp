class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        
        // Check all subarrays starting at index i
        for (int i = 0; i < n; i++) {
            // Try both increasing and decreasing subarrays
            // For increasing subarrays
            int incLen = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1]) {
                    incLen++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, incLen);
            
            // For decreasing subarrays
            int decLen = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[j - 1]) {
                    decLen++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, decLen);
        }
        
        return maxLen;
    }
};

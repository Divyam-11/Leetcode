class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int res = 1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        vector<int> freq(maxi + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for (int i = 1; i < freq.size(); i++)
        {
            freq[i] += freq[i - 1];
        }
        for (int i = mini; i <= maxi; i++)
        {
            int left_bound = max(i - k, mini);
            int right_bound = min(i + k, maxi);
            int f = freq[i] - freq[i-1];
            int extra = min(numOperations,freq[right_bound] - freq[left_bound-1] - f);
            res = max(extra+f, res);
        }
        return res;
    }
};
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3) return 0; 

        vector<int> prefix_max(n, 0);
        vector<int> suffix_max(n, 0);

        prefix_max[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix_max[i] = max(prefix_max[i - 1], nums[i - 1]);
        }

        suffix_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix_max[i] = max(suffix_max[i + 1], nums[i + 1]); 
        }

        long long result = 0;
        for (int j = 1; j < n - 1; j++)
        {
            int i = prefix_max[j]; 
            int k = suffix_max[j]; 
            if (i > nums[j]) 
            {
                result = max(result, (long long)(i - nums[j]) * k);
            }
        }
        return result;
    }
};

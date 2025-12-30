class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int maxSum = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> rem0;
        vector<int> rem1;
        vector<int> rem2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 3 == 0)
            {
                rem0.push_back(nums[i]);
            }
            if (nums[i] % 3 == 1)
            {
                rem1.push_back(nums[i]);
            }
            if (nums[i] % 3 == 2)
            {
                rem2.push_back(nums[i]);
            }
        }
        if (rem0.size() >= 3)
        {
            maxSum = rem0[0] + rem0[1] + rem0[2];
        }
        if (rem1.size() >= 3)
        {
            maxSum = max(maxSum, rem1[0] + rem1[1] + rem1[2]);
        }
        if (rem2.size() >= 3)
        {
            maxSum = max(maxSum, rem2[0] + rem2[1] + rem2[2]);
        }
        if (rem0.size() >= 1 && rem1.size() >= 1 && rem2.size() >= 1)
        {
            maxSum = max(maxSum, rem0[0] + rem1[0] + rem2[0]);
        }
        return maxSum;
    }}; 
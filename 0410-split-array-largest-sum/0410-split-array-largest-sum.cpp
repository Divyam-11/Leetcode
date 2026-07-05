class Solution
{
public:
    bool check(long long ans, vector<int> &nums, int k)
    {  
        long long runningSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (runningSum + nums[i] <= ans)
            {
                runningSum += nums[i];
            }
            else
            {
                runningSum = nums[i];
                k--;
            }
        }
        return k >= 1;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int maxi = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(nums[i], maxi);
        }
        int res = -1;
        long long low = maxi;
        long long high = sum;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (check(mid, nums, k))
            {
                res = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
};
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int res = INT_MIN;
        int n = nums.size();
        int F = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && i < nums.size() - 1)
                sum += nums[i];
            F += i * nums[i];
        }
        res = max(F,res);
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            F -= nums[i] * (n-1);
            F += sum;
            int temp = (i + 1) % n;
            F += nums[temp];
            sum += nums[temp];
            sum -= nums[i - 1];
            res = max(F, res);
        }
        return res;
    }
};
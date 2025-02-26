class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int kadane = INT_MIN;
        int ans = 0;
        for (auto i : nums)
        {
            ans += i;
            kadane = max(kadane, ans);
            if (ans < 0)
            {
                ans = 0;
            }
        }
        int reverse_kadane = INT_MIN;
         ans = 0;
        for (auto i : nums)
        {
            ans += i;
            reverse_kadane = max(reverse_kadane, abs(ans));
            if (ans > 0)
            {
                ans = 0;
            }
        }
        return max(reverse_kadane, kadane);
    }
};
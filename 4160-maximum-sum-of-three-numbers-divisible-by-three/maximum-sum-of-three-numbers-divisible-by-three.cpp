class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        priority_queue<int> mod0;
        priority_queue<int> mod1;
        priority_queue<int> mod2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 3 == 0)
            {
                mod0.push(nums[i]);
            }
            if (nums[i] % 3 == 1)
            {
                mod1.push(nums[i]);
            }
            if (nums[i] % 3 == 2)
            {
                mod2.push(nums[i]);
            }
        }
        // 0 1 2
        int sum = 0;
        if (!mod0.empty() && !mod1.empty() && !mod2.empty())
            sum = max(sum, (mod0.top() + mod1.top() + mod2.top()));
        int mod0_sum = 0;
        int mod1_sum = 0;
        int mod2_sum = 0;
        for (int i = 0; i < 3; i++)
        {
            if (mod0.empty())
                mod0_sum = -1;
            else
            {
                mod0_sum += mod0.top();
                mod0.pop();
            }
            if (mod1.empty())
                mod1_sum = -1;
            else
            {
                mod1_sum += mod1.top();
                mod1.pop();
            }
            if (mod2.empty())
                mod2_sum = -1;
            else
            {
                mod2_sum += mod2.top();
                mod2.pop();
            }
        }
        sum = max({sum, mod0_sum, mod1_sum, mod2_sum});
        return sum;
    }
};
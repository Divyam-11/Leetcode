class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int left_pre = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            left_pre += nums[i];
            int right_pre = sum - left_pre;
            int diff = left_pre - right_pre;
            if (diff % 2 == 0)
            {
                res++;
                        }
        }
        return res;
    }
};
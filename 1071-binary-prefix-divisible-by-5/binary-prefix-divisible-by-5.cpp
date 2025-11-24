class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        int num = 0;
        vector<bool> res(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            num = num << 1 | nums[i];
            num = num % 5;
            
            if (num % 5 == 0)
            {
                res[i] = true;
            }
        }
        return res;
    }
};
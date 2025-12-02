class Solution
{
public:
    int reverse_num(int x)
    {
        int rem;
        long res = 0;
        bool negative = false;
        while (x != 0)
        {
            rem = x % 10;
            x = x / 10;
            res = res * 10 + rem;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        else if (negative == true)
            return -res;
        else
            return res;
    }

    int minMirrorPairDistance(vector<int> &nums)
    {
        int res = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = reverse_num(nums[i]);
            if (mp.find(nums[i]) != mp.end())
            {
                res = min(res, i - mp[nums[i]]);
            }
            mp[temp] = i;
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};
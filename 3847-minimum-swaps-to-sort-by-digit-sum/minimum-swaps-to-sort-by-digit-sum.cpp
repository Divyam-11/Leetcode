class Solution
{
public:
    int digitSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit;
            n = n / 10;
        }
        return sum;
    }
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> num(nums.size());
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            num[i] = {digitSum(nums[i]), nums[i]};
            mp[nums[i]] = i;
        }
        int swaps = 0;
        sort(num.begin(), num.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != num[i].second)
            {
                int idx = mp[num[i].second];
                swap(nums[i], nums[idx]);
                mp[nums[i]] = i;
                mp[nums[idx]] = idx;
                swaps++;
            }
        }
    return swaps;
    }
};
class Solution
{
public:
    bool isPalindrome(int num)
    {
        if (num == 0)
            return true;
        string temp;
        while (num != 0)
        {
            temp.push_back(num % 2 + '0');
            num = num / 2;
        }

        int l = 0;
        int r = temp.size() - 1;
        while (l <= r)
        {
            if (temp[l] != temp[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<int> minOperations(vector<int> &nums)
    {
        vector<int> res;

        vector<int> cache;
        for (int i = 0; i <= 5000; i++)
        {
            if (isPalindrome(i))
            {
                cache.push_back(i);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            auto ub = upper_bound(cache.begin(), cache.end(), nums[i]);
            int temp = 5000;
            if (ub != cache.end())
            {
                temp = *ub - nums[i];
            }
            if (ub != cache.begin())
            {
                temp = min(temp, nums[i] - *prev(ub));
            }
            res.push_back(temp);
        }
        return res;
    }
};
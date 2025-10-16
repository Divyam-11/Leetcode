class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[((nums[i]%value)+value)%value]++;
        }
        for (int i = 0; i < 1e5 + 1; i++)
        {
            int val = i % value;
            if (mp[val] != 0)
            {
                mp[val]--;
            }
            else
                return i;
        }
        return 1e5 + 1;
    }
};
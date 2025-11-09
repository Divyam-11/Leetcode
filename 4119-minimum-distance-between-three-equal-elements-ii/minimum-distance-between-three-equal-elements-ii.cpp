class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        int res = INT_MAX;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]].size() >= 2)
            {

                int a = i;
                int b = mp[nums[i]][0];
                int c = mp[nums[i]][1];
                mp[nums[i]][0] = c;
                mp[nums[i]][1] = a;
                int score = abs(a - b) + abs(a - c) + abs(b - c);
                res = min(res, score);
            }
            else
                mp[nums[i]].push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};
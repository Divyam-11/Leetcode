class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        vector<long long> ans(arr.size());
        unordered_map<int, vector<long long>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = {1, i, 0};
            }
            else
            {
                auto temp = mp[arr[i]];
                ans[i] += temp[2] + temp[0] * abs(i - temp[1]);
                mp[arr[i]] = {temp[0] + 1, i, ans[i]};
            }
        }
        mp.clear();
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = {1, i, 0};
            }
            else
            {
                auto temp = mp[arr[i]];
                long long sc = temp[2] + temp[0] * abs(i - temp[1]);
                ans[i] +=  sc;
                mp[arr[i]] = {temp[0] + 1, i, sc};
            }
        }
        return ans;
    }
};
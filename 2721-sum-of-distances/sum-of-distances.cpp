class Solution
{
public:
    vector<long long> distance(vector<int> &arr)
    {
        vector<long long> ans(arr.size());
        unordered_map<int, tuple<long long, long long, long long>> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = {1, i, 0};
            }
            else
            {
                auto temp = mp[arr[i]];
                long long cnt = get<0>(temp);
                long long last = get<1>(temp);
                long long sum = get<2>(temp);

                ans[i] += sum + cnt * abs(i - last);
                mp[arr[i]] = {cnt + 1, i, ans[i]};
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
                long long cnt = get<0>(temp);
                long long last = get<1>(temp);
                long long sum = get<2>(temp);

                long long sc = sum + cnt * abs(i - last);
                ans[i] += sc;
                mp[arr[i]] = {cnt + 1, i, sc};
            }
        }
        return ans;
    }
};

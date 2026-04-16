class Solution
{
public:
    int getMin(vector<int> &words, int x, int y)
    {
        int i = min(x, y);
        int j = max(x, y);
        int res = abs(j - i);
        // cout<<x<<" "<<y<<endl;
        
        int temp = abs(j - (int)words.size() - i);
        res = min(temp, res);
        temp = abs(j + (int)words.size() - i);
        res = min(temp, res);
        return res;
    }
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> result;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int res = INT_MAX;
            int val = nums[queries[i]];
            if (mp[val].size() == 1)
            {
                result.push_back(-1);
                continue;
            }
            int idx = (lower_bound(mp[val].begin(), mp[val].end(), queries[i]) - mp[val].begin());
            int left_idx = (idx + 1) % mp[val].size();
            int right_idx = ((idx - 1) + mp[val].size()) % mp[val].size();
            // cout<<mp[val][idx]<<" "<<mp[val][left_idx]<<" "<<mp[val][right_idx]<<endl;
            res = min(getMin(nums, mp[val][idx], mp[val][left_idx]), getMin(nums, mp[val][idx], mp[val][right_idx]));
            result.push_back(res);
        }
        return result;
    }
};
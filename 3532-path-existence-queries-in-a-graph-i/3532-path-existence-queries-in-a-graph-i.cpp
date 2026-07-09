class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<bool> res;
        int par = 0;
        
        unordered_map<int, int> mp; 
        mp[0] = 0;// {num,par}
        for (int i = 1; i < nums.size(); i++)
        {   
            if (abs(nums[i] - nums[i-1]) > maxDiff)
            {
                par = i;
            }
            mp[i] = par;
            // cout<<par<<endl;
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            if (mp[v] == mp[u])
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};
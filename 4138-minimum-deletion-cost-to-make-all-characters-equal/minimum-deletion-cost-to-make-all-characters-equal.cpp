class Solution
{
public:
    long long minCost(string s, vector<int> &cost)
    {
        long long total_cost = 0;
        unordered_map<char, long long> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i] - 'a'] += cost[i];
            total_cost += cost[i];
        }
        long long minCost = LLONG_MIN;
        for (auto i : mp)
        {
            minCost = max(minCost, (long long)i.second);
        }
        return total_cost - minCost;
    }
};

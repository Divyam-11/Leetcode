class Solution
{
public:
    int dp[1001][1501][2];
    int solve(int index, int budget, bool first_pick, vector<int> &preComp, vector<vector<int>> &items)
    {
        if (index < 0 || budget < 0)
            return 0;
        if (budget == 0)
            return 0;
        if (dp[index][budget][first_pick] != -1)
            return dp[index][budget][first_pick];
        int take = INT_MIN;
        if (budget >= items[index][1])
        {
            take = 1 + solve(index, budget - items[index][1], false, preComp, items) + preComp[index] * (int)first_pick;
        }
        int not_take = solve(index - 1, budget, true, preComp, items);
        return dp[index][budget][first_pick] = max(take, not_take);
    }
    int maximumSaleItems(vector<vector<int>> &items, int budget)
    {

        vector<int> preComp(items.size());
        for (int i = 0; i < items.size(); i++)
        {
            for (int j = 0; j < items.size(); j++)
            {
                if (i != j && items[j][0] % items[i][0] == 0)
                {
                    preComp[i]++;
                }
            }
        }
        bool first_pick = true;
        memset(dp, -1, sizeof(dp));
        return solve(items.size() - 1, budget, first_pick, preComp, items);
    }
};
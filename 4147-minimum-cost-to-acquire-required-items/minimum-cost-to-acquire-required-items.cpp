class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        long long minCost = 0;
        if (cost1 + cost2 < costBoth)
        {
            minCost += cost1 * 1LL* need1 + cost2 *1LL* need2;
            return minCost;
        }
        int canPick = min(need1, need2);
        need1 -= canPick;
        need2 -= canPick;
        minCost += canPick * 1LL * costBoth;
        if (need1 != 0)
        {
            minCost += need1 * 1LL*min(cost1, costBoth);
        }
        if (need2 != 0)
        {
            minCost += need2 * 1LL* min(cost2, costBoth);
        }
        return minCost;
    }
};
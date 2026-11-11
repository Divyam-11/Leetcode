class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        long long ans = 0;
        if (costBoth <= cost1 + cost2)
        {
            int temp = min(need1, need2);
            ans += costBoth *1LL * min(need1, need2);
            
            need1 -= temp;
            need2 -= temp;
             
            if (need1 > 0)
            {
                ans += min(cost1, costBoth) *1LL* need1;
            }
            if (need2 > 0)
            {
                ans += min(cost2, costBoth) *1LL* need2;
            }
            return ans;
        }
        ans = need1 *1LL* cost1 + need2 *1LL * cost2;
        return ans;
    }
};
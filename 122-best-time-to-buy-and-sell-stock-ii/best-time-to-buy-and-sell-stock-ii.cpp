class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index = n - 1; index >= 0; index--)
        {
            int profit = 0;
            for(int buy = 0; buy <= 1; buy++)
            {
                if(buy)
                {
                    int Buy = -prices[index] + next[0];
                    int skip = 0 + next[1];
                    profit = max(Buy,skip);
                }
                else
                {
                    int sell = prices[index] + next[1];
                    int skip = 0 + next[0];
                    profit = max(sell,skip);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];

    }
};
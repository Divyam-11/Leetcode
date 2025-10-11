class Solution
{
public:
    int climbStairs(int n, vector<int> &costs)
    {
        vector<int> dp(costs.size()+1,0);
        for (int j = 1; j <= costs.size(); j++)
        {   
           
            int temp_cost = INT_MAX;    
            for (int k = 1; k <= 3; k++)
            {   
                int i = j - k;
                if(i < 0) break;
                
                int temp = dp[i] + costs[j-1] + (j-i)*(j-i);
                temp_cost = min(temp,temp_cost);
            }
            dp[j] = temp_cost;

        }
        return dp.back();
    }
};
class Solution { 
    vector<vector<vector<long long>>> dp;


    long long recur(int i, int k, int flag, vector<int>& prices, int n){
        if(i >= n){
            if(flag == 0) return 0;
            return INT_MIN/2;
        }
        if(k == 0) return 0;

        if(dp[i][k][flag] != -1) return dp[i][k][flag];

        
        long long take = INT_MIN;
        if(flag == 0){
            
            long long buy = - prices[i] + recur(i + 1, k, 2, prices, n);
            long long shortSell = prices[i] + recur(i + 1, k, 1, prices, n);

            take = max(buy, shortSell);
        }else if(flag == 1){
            
            take = - prices[i] + recur(i + 1, k - 1, 0, prices, n); 
        }else{
           
            take = prices[i] + recur(i + 1, k - 1, 0, prices, n);
        }

        long long skip = recur(i + 1, k, flag, prices, n);

        return dp[i][k][flag] = max(take, skip);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp.assign(n, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));

        return recur(0,k,0, prices, n);

    }
};
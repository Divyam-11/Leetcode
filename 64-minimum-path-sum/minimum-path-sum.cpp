class Solution {
    int helper(int i,int j,vector<vector<int>> & grid,int m ,int n,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 100000;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 && j == 0 ) return grid[0][0];
        int down = helper(i,j-1,grid,m,n,dp) + grid[i][j];
        int right = helper(i-1,j,grid,m,n,dp) + grid[i][j];
        return dp[i][j] = min(down,right);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
            vector<vector<int>> dp(m,vector<int>(n,-1));
    return helper(m-1,n-1,grid,m,n,dp);
    }
};
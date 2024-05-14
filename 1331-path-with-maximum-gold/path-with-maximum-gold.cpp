class Solution {
    
    void solve(int row,int column,int &collected,vector<vector<int>> &grid,int &result){
        if(row < 0 || column < 0 || row >= grid.size() || column>= grid[0].size()) return ;
        if(grid[row][column] == 0 || grid[row][column] == -1){
            return ;
        }
        int gold = grid[row][column];
        grid[row][column] = -1;
        result = max(collected,result);
        collected+=gold;
        result = max(collected,result);
        solve(row+1,column,collected,grid,result);
        solve(row,column+1,collected,grid,result);
        solve(row-1,column,collected,grid,result);
        solve(row,column-1,collected,grid,result);
        collected-=gold;
        grid[row][column ] = gold;
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = INT_MIN;
        
        for(int i = 0 ; i  < grid.size();i++){
            for(int j = 0 ; j  <  grid[0].size();j++){
                int collected = 0 ;
                solve(i,j,collected,grid,result);
            }
        }
        if(result != INT_MIN)
        return result;
        return 0;
    }
};
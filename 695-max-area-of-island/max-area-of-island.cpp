class Solution
{
    private:
    void dfs(int row,int col,vector<vector<int>> & grid,vector<vector<int>> & visited,int &counter){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] ==0) return;
        if(visited[row][col]) return;

        visited[row][col] = 1;
        counter++;


        dfs(row+1,col,grid,visited,counter);
        dfs(row,col+1,grid,visited,counter);
        dfs(row-1,col,grid,visited,counter);
        dfs(row,col-1,grid,visited,counter);
        

    }
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
       int result = 0; 
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0 ;i < grid.size();i++){
            for(int j = 0 ; j < grid[0].size();j++){
                
                if(!visited[i][j] && grid[i][j] == 1){
                    int counter = 0; 
                    dfs(i,j,grid,visited,counter);
                    result = max(result,counter);
                }
            }
        }
    return result;
    }
};
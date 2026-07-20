class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for(int i = 0 ;i < grid.size();i++){
            for(int j = 0 ;j < grid[0].size();j++){
            temp.push_back(grid[i][j]);
            }
        }
        int index = k % temp.size();
        
        int n = temp.size();
        index = n - index;
        index = index % n;
        for(int i = 0 ;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                grid[i][j] = temp[index];
                index = (index+1)%n;
            }
        }
        return grid;
    }
};
class Solution
{
public:
    bool isMagic(int x, int y, vector<vector<int>> &grid)
    {
        if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1)
        {
            return false;
        }
        cout<<x<<y<<endl;
        int sum = grid[x - 1][y - 1] + grid[x][y] + grid[x + 1][y + 1];
        int temp_sum = grid[x + 1][y - 1] + grid[x][y] + grid[x - 1][y + 1];
        if (sum != temp_sum)
            return false;
        set<int> st;
        for (int i = 0; i < 3; i++)
        {
            int row_sum = 0;
            int col_sum = 0;
            for (int j = 0; j < 3; j++)
            {
                row_sum += grid[x-1+i][y-1+j];
                col_sum += grid[x-1+j][y-1+i];
                if (grid[x-1+i][y-1+j] > 9 || grid[x-1+i][y-1+j] == 0)
                    return false;
                st.insert(grid[x-1+i][y-1+j]);
            }
            if (sum != row_sum || sum != col_sum)
                return false;
        }

        return st.size() == 9;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 1; i < grid.size()-1; i++)
        {
            for (int j = 1; j < grid[0].size(); j++)
            {
                if (isMagic(i, j, grid))
                    res++;
            }
        }
        return res;
    }
};
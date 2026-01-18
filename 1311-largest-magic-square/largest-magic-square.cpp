class Solution
{
public:
    bool check(int i, int j, int k, vector<vector<int>> &grid, vector<vector<int>> &rowPre, vector<vector<int>> &colPre, vector<vector<int>> &TdiagPre, vector<vector<int>> &BdiagPre)
    {
        int benchmark = rowPre[i][j + k - 1] - rowPre[i][j] + grid[i][j];
        for (int x = 0; x < k; x++)
        {
            if (benchmark != (rowPre[i + x][j + k - 1] - rowPre[i + x][j] + grid[i + x][j]))
                return false;
            if (benchmark != (colPre[i + k - 1][j + x] - colPre[i][j + x] + grid[i][j + x]))
                return false;
        }
        if (benchmark != (TdiagPre[i + k - 1][j + k - 1] - TdiagPre[i][j] + grid[i][j]))
            return false;
        if (benchmark != (BdiagPre[i][j + k - 1] - BdiagPre[i + k - 1][j] + grid[i + k - 1][j]))
            return false;
        return true;
    }
    // void printMatrix(const vector<vector<int>> &mat)
    // {
    //     static int call = 1;
    //     cout << "==== Matrix " << call++ << " ====\n";
    //     for (const auto &row : mat)
    //     {
    //         for (int val : row)
    //             cout << val << " ";
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    int largestMagicSquare(vector<vector<int>> &grid)
    {
        vector<vector<int>> rowPre(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> colPre(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> TdiagPre(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> BdiagPre(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++)
        {
            rowPre[i][0] = grid[i][0];
            for (int j = 1; j < grid[0].size(); j++)
            {
                rowPre[i][j] = rowPre[i][j - 1] + grid[i][j];
            }
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            colPre[0][i] = grid[0][i];

            for (int j = 1; j < grid.size(); j++)
            {
                colPre[j][i] = colPre[j - 1][i] + grid[j][i];
            }
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            int x = 0;
            int y = i;
            int sum = 0;
            while (x < grid.size() && y < grid[0].size())
            {
                sum += grid[x][y];
                TdiagPre[x][y] = sum;
                x++;
                y++;
            }
        }
        for (int i = 1; i < grid.size(); i++)
        {
            int x = i;
            int y = 0;
            int sum = 0;
            while (x < grid.size() && y < grid[0].size())
            {
                sum += grid[x][y];
                TdiagPre[x][y] = sum;
                x++;
                y++;
            }
        }
        // for (int i = 0; i < grid[0].size(); i++)
        // {
        //     int x = grid.size() - 1;
        //     int y = i;
        //     int sum = 0;
        //     while (x < grid.size() && y >= 0)
        //     {
        //         sum += grid[x][y];
        //         BdiagPre[x][y] = sum;
        //         x++;
        //         y--;
        //     }
        // }
        // for (int i = grid.size() - 1; i >= 0; i--)
        // {
        //     int x = i;
        //     int y = grid[0].size() - 1;
        //     int sum = 0;
        //     while (x >= 0 && y < grid[0].size())
        //     {
        //         sum += grid[x][y];
        //         BdiagPre[x][y] = sum;
        //         x--;
        //         y++;
        //     }
        // }
        for (int i = 0; i < grid.size() - 1; i++)
        {
            int x = i;
            int y = 0;
            int sum = 0;
            while (x >= 0 && y < grid[0].size())
            {
                sum += grid[x][y];
                BdiagPre[x][y] = sum;
                x--;
                y++;
            }
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            int x = grid.size() - 1;
            int y = i;
            int sum = 0;
            while (x >= 0 && y < grid[0].size())
            {
                sum += grid[x][y];
                BdiagPre[x][y] = sum;
                x--;
                y++;
            }
        }
        // printMatrix(rowPre);
        // printMatrix(colPre);
        // printMatrix(TdiagPre);
        // printMatrix(BdiagPre);
        int maxSide = 1;
        for (int i = 0; i < grid.size(); i++)
        {

            for (int j = 0; j < grid[0].size(); j++)
            {
                int k = 2;
                while (k <= (grid.size() - i) && k <= (grid[0].size() - j))
                {
                    if (check(i, j, k, grid, rowPre, colPre, TdiagPre, BdiagPre))
                    {
                        maxSide = max(maxSide, k);
                    }
                    k++;
                }
            }
        }
        return maxSide;
        return 0;
    }
};
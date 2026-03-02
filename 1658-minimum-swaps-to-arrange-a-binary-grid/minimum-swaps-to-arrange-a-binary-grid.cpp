class Solution
{
public:
    int getSuffix(int row, vector<vector<int>> &grid)
    {
        int zeros = 0;
        for (int j = grid[0].size() - 1; j >= 0; j--)
        {
            if (grid[row][j] == 0)
                zeros++;
            else
                break;
        }
        return zeros;
    }
    int getReplacement(int row, vector<int> &mp)
    {
        int idx = -1;
        for (int i = row; i < mp.size(); i++)
        {
            int neededZero = mp.size() - row - 1;
            if (mp[i] >= neededZero)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return -1;
        for (int i = idx; i > row; i--)
        {
            swap(mp[i], mp[i - 1]);
        }
        return idx;
    }
    int minSwaps(vector<vector<int>> &grid)
    {
        int res = 0;
        vector<int> mp(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            mp[i] = getSuffix(i, grid);
        }
        for (int i = 0; i < grid.size(); i++)
        {
            int temp = mp.size() - i - 1;
            if (mp[i] < temp)
            {
                int idx = getReplacement(i, mp);
                if (idx == -1)
                    return -1;

                res += idx - i;
            }
        }
        return res;
    }
};
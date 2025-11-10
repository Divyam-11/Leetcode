class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<long long, int> columns;
        for (int i = 0; i < wall.size(); i++)
        {
            long long border = 0;
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                border += wall[i][j];
                columns[border]++;
            }
        }
        int res = wall.size();
        for (auto i : columns)
        {
            res = min(res, (int)wall.size() - i.second);
        }
        return res;
    }
};
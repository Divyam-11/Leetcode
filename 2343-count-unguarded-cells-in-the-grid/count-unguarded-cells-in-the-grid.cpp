class Solution
{
public:
    void solve(int x, int y, set<pair<int, int>> &g, set<pair<int, int>> &w, vector<vector<int>> &visited)
    {
        int i = x + 1;
        while (i < visited.size())
        {
            if (g.find({i, y}) != g.end() || w.find({i, y}) != w.end())
            {
                break;
            }
            visited[i][y] = true;
            i++;
        }
        i = x - 1;
        while (i >= 0)
        {
            if (g.find({i, y}) != g.end() || w.find({i, y}) != w.end())
            {
                break;
            }
            visited[i][y] = true;
            i--;
        }
        int j = y + 1;
        while (j < visited[0].size())
        {
            if (g.find({x, j}) != g.end() || w.find({x, j}) != w.end())
            {
                break;
            }
            visited[x][j] = true;
            j++;
        }
        j = y - 1;
        while (j >= 0)
        {
            if (g.find({x, j}) != g.end() || w.find({x, j}) != w.end())
            {
                break;
            }
            visited[x][j] = true;
            j--;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        set<pair<int, int>> g;
        set<pair<int, int>> w;

        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < walls.size(); i++)
        {
            int x = walls[i][0];
            int y = walls[i][1];
            matrix[x][y] = true;
            w.insert({x, y});
        }
        for (int i = 0; i < guards.size(); i++)
        {
            int x = guards[i][0];
            int y = guards[i][1];
            matrix[x][y] = true;
            g.insert({x, y});
        }
        for (int i = 0; i < guards.size(); i++)
        {
            solve(guards[i][0], guards[i][1], g, w, matrix);
        }
        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (!matrix[i][j])
                    res++;
            }
        }
        return res;
    }
};
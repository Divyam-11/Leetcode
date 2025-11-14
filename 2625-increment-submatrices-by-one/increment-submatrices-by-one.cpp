class Solution
{
public:
    void solve(int a, int b, int c, int d, vector<vector<int>> &matrix)
    {
        for (int i = a; i <= c; i++)
        {
            for (int j = b; j <= d; j++)
            {
                matrix[i][j]++;
            }
        }
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < queries.size(); i++)
        {
            solve(queries[i][0], queries[i][1], queries[i][2], queries[i][3], mat);
        }
        return mat;
    }
};
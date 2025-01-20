class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row_index((m * n) + 1, 0);
        vector<int> column_index((m * n) + 1, 0);
        vector<int> rowfreq(m, 0);
        vector<int> colfreq(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int value = mat[i][j];
                row_index[value] = i;
                column_index[value] = j;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            int value = arr[i];
            int x = row_index[value];
            int y = column_index[value];
            rowfreq[x]++;
            colfreq[y]++;
            if (rowfreq[x] == n || colfreq[y] == m)
                return i;
        }
        return -1;
    }
};
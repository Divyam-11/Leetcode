class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adjMatrix, vector<int> &visited)
    {
        visited[node] = 1;
        for (int i = 0; i < adjMatrix.size(); i++)
        {
            if (adjMatrix[node][i])
            {
                if (!visited[i])
                    dfs(i, adjMatrix, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> visited(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited);
                res++;
            }
        }
        return res;
    }
};
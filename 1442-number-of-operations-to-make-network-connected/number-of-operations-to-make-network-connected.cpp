class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adjList[node])
        {
            if (!visited[it])
            {
                dfs(it, adjList, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {

        int edgesCount = connections.size();
        if (edgesCount < n - 1)
            return -1;
        vector<vector<int>> adjList(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int components = 0;
        vector<int> visited(n);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                components++;
                dfs(i, adjList, visited);
            }
        }
        return components - 1;
    }
};
class Solution
{
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited)
    {
        visited[node] = 1;
        for (int i = 0; i < adjList[node].size(); i++)
        {
            if (!visited[adjList[node][i]])
            {
                dfs(adjList[node][i], adjList, visited);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        vector<vector<int>> adjList(n);
        vector<int> visited(n, 0);
        for (int i = 0; i < connections.size(); i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }

        int result = 0;
        for (int i = 0; i < adjList.size(); i++)
        {
            if (!visited[i])
            {

                dfs(i, adjList, visited);
                result++;
            }
        }
        return result - 1;
    }
};
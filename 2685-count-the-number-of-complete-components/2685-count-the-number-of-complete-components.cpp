class Solution
{
public:
    void dfs(int n, int node, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &nodes)
    {
        if (visited[node])
            return;
        visited[node] = 1;
        for (auto it : adjList[node])
        {
            dfs(n, it, adjList, visited, nodes);
        }
        nodes.push_back(node);
        
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);
        vector<int> visited(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> nodes;
                dfs(n, i, adjList, visited, nodes);
                bool flag = true;
                int count = nodes.size();
                for (auto node : nodes)
                {
                    if (adjList[node].size() != count - 1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    components++;
            }
        }
        return components;
    }
};
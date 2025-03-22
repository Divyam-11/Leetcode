class Solution
{
    void dfs(int node, vector<vector<int>> &adjList, unordered_set<int> &nodes, vector<int> &visited)
    {
        if (visited[node])
            return;
        visited[node] = true;
        nodes.insert(node);
        for (int i = 0; i < adjList[node].size(); i++)
        {
            dfs(adjList[node][i], adjList, nodes, visited);
        }
        return;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        int CompleteComponents = 0;
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n);
        for (int i = 0; i < adjList.size(); i++)
        {
            if (!visited[i])
            {
                unordered_set<int> nodes;
                dfs(i, adjList, nodes, visited);
                int edgesCount = 0;
                for (int i = 0; i < adjList.size(); i++)
                {
                    if (nodes.find(i) != nodes.end())
                    {
                        edgesCount += adjList[i].size();
                    }
                }
                edgesCount /= 2;
                if (edgesCount == ((nodes.size() * (nodes.size() - 1)) / 2))
                {
                    CompleteComponents++;
                }
            }
        }
        return CompleteComponents;
    }
};
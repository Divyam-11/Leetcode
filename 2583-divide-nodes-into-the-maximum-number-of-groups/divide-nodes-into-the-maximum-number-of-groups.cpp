class Solution
{
public:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph)
    {
        color[node] = col;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (dfs(it, !col, color, graph) == false)
                    return false;
            }
            else if (color[it] == col)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color = vector<int>(graph.size(), -1);

        for (int i = 0; i < color.size(); i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
    
    vector<vector<int>> getConnectedComponents(vector<vector<int>>& adjList, vector<int> &visited)
    {
        vector<vector<int>> components;
        for (int i = 0; i < adjList.size(); i++)
        {
            if (!visited[i])
            {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for (auto neighbor : adjList[node])
                    {
                        if (!visited[neighbor])
                        {
                            visited[neighbor] = 1;
                            q.push(neighbor);
                        }
                    }
                }
                components.push_back(component);
            }
        }
        return components;
    }
    
    int bfsMaxDepth(int start, vector<vector<int>>& adjList)
    {
        queue<int> q;
        unordered_map<int, int> depth;
        q.push(start);
        depth[start] = 1;
        int maxDepth = 1;
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbor : adjList[node])
            {
                if (!depth.count(neighbor))
                {
                    depth[neighbor] = depth[node] + 1;
                    maxDepth = max(maxDepth, depth[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return maxDepth;
    }
    
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adjList[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        if (!isBipartite(adjList))
            return -1;
        
        vector<int> visited(n, 0);
        vector<vector<int>> components = getConnectedComponents(adjList, visited);
        int maxGroups = 0;
        
        for (auto& component : components)
        {
            int localMax = 0;
            for (int node : component)
            {
                localMax = max(localMax, bfsMaxDepth(node, adjList));
            }
            maxGroups += localMax;
        }
        
        return maxGroups;
    }
};
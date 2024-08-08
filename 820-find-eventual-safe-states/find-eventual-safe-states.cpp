class Solution
{
private:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited, vector<int> &check)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : graph[node])
        {
            if (!visited[it])
            {
                if (dfs(it, graph, visited, pathVisited, check))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVisited[it])
            {
                check[node] = 0;
                return true;
            }
        }
        pathVisited[node] = 0;
        check[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> result;
        vector<int> visited = vector<int>(graph.size(), 0);
        vector<int> pathVisited = visited;
        vector<int> check = visited;
        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, visited, pathVisited, check);
            }
        }
        for (int i = 0; i < graph.size(); i++)
        {
            if (check[i] == 1)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
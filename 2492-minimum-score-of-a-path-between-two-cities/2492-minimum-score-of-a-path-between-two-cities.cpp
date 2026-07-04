class Solution
{
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adjList, int n, vector<int> &visited, int &minPath)
    {

        if (visited[node])
            return;

        int res = INT_MAX;
        visited[node] = 1;
        for (auto &i : adjList[node])
        {
            
            minPath = min(i.second, minPath);
            dfs(i.first, adjList, n, visited, minPath);
        }
        
    }
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < roads.size(); i++)
        {
            adjList[roads[i][0] - 1].push_back({roads[i][1] - 1, roads[i][2]});
            adjList[roads[i][1] - 1].push_back({roads[i][0] - 1, roads[i][2]});
        }
        vector<int> visited(n);
        int minPath = INT_MAX;
        dfs(0, adjList, n, visited, minPath);
        return minPath;
    }
};
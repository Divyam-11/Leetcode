class Solution
{
public:
    bool canRemove = true;
    void dfs1(int node, vector<vector<int>> &adjList, vector<int> &visited)
    {
        if (visited[node])
            return;
        visited[node] = true;
        for (auto i : adjList[node])
        {
            if (!visited[i])
            {
                dfs1(i, adjList, visited);
            }
        }
    }
    void dfs2(int node, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &infected)
    {
        if (!canRemove)
            return;
        if (infected[node])
        {
            canRemove = false;
            return;
        }
        if (visited[node])
            return;
        visited[node] = true;

        for (auto i : adjList[node])
        {

            dfs2(i, adjList, visited, infected);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < invocations.size(); i++)
        {
            adjList[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> visited(n);
        vector<int> infected(n);
        dfs1(k, adjList, infected);
        for (int i = 0; i < n; i++)
        {
            if (!infected[i] && !visited[i])
            {
                dfs2(i, adjList, visited, infected);
                if (canRemove == false)
                    break;
            }
        }
        if (canRemove)
        {
            vector<int> res;
            for (int i = 0; i < n; i++)
            {
                if (!infected[i])
                {
                    res.push_back(i);
                }
            }
            return res;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(i);
        }
        return res;
    }
};
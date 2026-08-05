class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &infected)
    {

        infected[node] = 0;
        for (auto it : adjList[node])
        {
            if(infected[it])
            dfs(it, adjList, infected);
        }
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < invocations.size(); i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[u].push_back(v);
        }
        queue<int> q;
        q.push(k);
        vector<int> infected(n);
        infected[k] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adjList[node])
            {
                if (!infected[it])
                {
                    infected[it] = 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < invocations.size(); i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[v].push_back(u);
        }
        for (int i = 0; i < adjList.size(); i++)
        {
            if (!infected[i])
            {
                dfs(i, adjList, infected);
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (infected[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};
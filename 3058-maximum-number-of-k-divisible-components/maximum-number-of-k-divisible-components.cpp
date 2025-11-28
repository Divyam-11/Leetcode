class Solution
{

public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        int ans = 0;

        int root = 0;

        for (const vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(root, values, k, adj, visited, ans);
        return ans;
    }

private:
    int dfs(int root, vector<int> &values, int k, unordered_map<int, vector<int>> &adj, unordered_set<int> &visited, int &ans)
    {
        if (visited.find(root) != visited.end())
        {
            return 0;
        }

        visited.insert(root);
        int temp = values[root];

        for (int neigh : adj[root])
        {
            temp += dfs(neigh, values, k, adj, visited, ans);
        }

        if (temp % k == 0)
        {
            ans++;
            return 0;
        }

        return temp % k;
    }
};
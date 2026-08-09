class DSU
{
public:
    vector<int> parent, rank;
    int n;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {

        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv)
            return;
        if (rank[pv] == rank[pu])
        {
            parent[pv] = pu;
            rank[pu]++;
        }
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
        }
    }
};
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        DSU ds(n);
        int components = 0;
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionByRank(u, v);
        }
        for (int i = 0; i < n; i++)
        {
            if (ds.findUParent(i) == i)
            {
                components++;
            }
        }
        return components - 1;
    }
};
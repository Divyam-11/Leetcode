 class DisjointSet
{
    vector<int> rank, size, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] == rank[pv])
        {
            parent[pv] = pu;
            rank[pu]++;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] >= size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
class Solution
{

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DisjointSet ds(edges.size() + 1);
        vector<int> result(2);
        for (int i = 0; i < edges.size(); i++)
        {
            if (ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1]))
            {
                result[0] = edges[i][0];
                result[1] = edges[i][1];
            }
            ds.unionByRank(edges[i][0], edges[i][1]);
        }
        return result;
    }
};
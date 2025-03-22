class DisjointSet
{
public:
    vector<int> rank, size, parent;

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
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        int result = 0;
        unordered_map<int, int> edgeCount;
        DisjointSet ds(n);
        for (int i = 0; i < edges.size(); i++)
        {
            ds.unionBySize(edges[i][0], edges[i][1]);
        }
        for (int i = 0; i < edges.size(); i++)
        {
            int root = ds.findUPar(edges[i][0]);
            edgeCount[root]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (ds.findUPar(i) == i)
            {
                int v_count = ds.size[i];
                int e_count = edgeCount[i];
                if (e_count == ((v_count) * (v_count - 1)) / 2)
                    result++;
            }
        }
        return result;
    }
};
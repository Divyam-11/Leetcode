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
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        int matchups = 0;
        DisjointSet ds(source.size());
        for (int i = 0; i < allowedSwaps.size(); i++)
        {
            ds.unionByRank(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        unordered_map<int, unordered_map<int, int>> sourcemp;
        unordered_map<int, unordered_map<int, int>> targmp;
        for (int i = 0; i < source.size(); i++)
        {
            sourcemp[ds.findUPar(i)][source[i]]++;
            targmp[ds.findUPar(i)][target[i]]++;
        }
        for (auto &ptr : sourcemp)
        {
            auto temp1 = ptr.second;
            auto temp2 = targmp[ptr.first];
            for (auto i : temp1)
            {
                int val = min(i.second, temp2[i.first]);
                matchups += val;
            }
        }
        return n - matchups;
    }
};
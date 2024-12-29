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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        maxRow = max(maxRow,maxCol);
        maxCol = max(maxRow,maxCol);
        unordered_map<int, int> stoneCounts;
        DisjointSet ds(maxRow + maxCol + 1);
        for (auto it : stones)
        {
            int row = it[0];
            int col = it[1] + maxCol + 1;
            ds.unionByRank(row, col);
            stoneCounts[row] = 1;
            stoneCounts[col] = 1;
        }
        int cnt = 0;
        for (auto it : stoneCounts)
        {
            if (ds.findUPar(it.first) == it.first)
            {
                cnt++;
            }
        }
        return n - cnt;
    }
};
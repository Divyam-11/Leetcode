class Solution
{
public:
class DSU
{
    vector<int> parent, rank, size;
    int n;
    public:
    DSU(int n)
    {
        this->n = n;
        parent.resize(n);
        rank.resize(n, 1);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pv == pu)
            return;
        if (rank[pu] == rank[pv])
        {
            rank[pu]++;
            parent[pv] = pu;
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
    int removeStones(vector<vector<int>> &stones)
    {
        int maxX = INT_MIN;
        int maxY = INT_MIN;
        int stone_count = stones.size();
        set<int> xs;
        set<int> ys;
        for (int i = 0; i < stones.size(); i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];
            maxX = max(maxX, x);
            maxY = max(maxY, y);
            xs.insert(x);
            ys.insert(y);
        }
        DSU ds(maxX + maxY + 2);
        for (int i = 0; i < stones.size(); i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];
            ds.unionByRank(x, maxX + 1 + y);
        }
        int count = 0;
        for (auto i : xs)
        {
            if (ds.findUParent(i) == i)
                count++;
        }
        for (auto i : ys)
        {
            if (ds.findUParent(i + maxX + 1) == i + maxX + 1)
                count++;
        }
        return stone_count - count;
    }
};
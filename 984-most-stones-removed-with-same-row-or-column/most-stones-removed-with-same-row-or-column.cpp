class Solution
{
public:
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
        DisjointSet ds(maxX + maxY + 1);
        for (int i = 0; i < stones.size(); i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];
            ds.unionByRank(x, maxX + 1 + y);
        }
        int count = 0;
        for (auto i : xs)
        {
            if (ds.findUPar(i) == i)
                count++;
        }
        for (auto i : ys)
        {
            if (ds.findUPar(i + maxX + 1) == i + maxX + 1)
                count++;
        }
        return stone_count - count;
    }
};
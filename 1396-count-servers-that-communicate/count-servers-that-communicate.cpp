class Solution
{
public:
    vector<int> parent, rank;
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
        if (pu == pv) return;
        if (rank[pu] >= rank[pv])
        {
            rank[pu] += rank[pv];
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv])
        {
            rank[pv] += rank[pu];
            parent[pu] = pv;
        }
    }
    int countServers(vector<vector<int>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m + n);
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
        rank.resize(m + n, 1);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j]){
                unionByRank(i, m + j);
                res++;
                }
            }
        }
       
        for(int i = 0; i < m+n;i++){
            if(findUParent(i) == i && rank[i] == 2) res--;
        }
        return res;
    }
};
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n + 1);
        unordered_map<string, int> mp;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mp.find(accounts[i][j]) != mp.end())
                {
                    ds.unionByRank(mp[accounts[i][j]], i);
                }
                else
                    mp[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> result(n);
        for (auto it : mp)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            result[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (result[i].size() == 0)
                continue;
            sort(result[i].begin(), result[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : result[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
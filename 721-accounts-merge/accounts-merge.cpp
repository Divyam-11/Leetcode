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
        unordered_map<string, int> mp;
        unordered_map<int, vector<string>> mpp;
        DisjointSet DS(n);

        for (int i = 0; i < n; i++)
        {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if (mp.find(email) == mp.end())
                {
                    mp[email] = i;
                }
                else
                {
                    DS.unionByRank(mp[email], i);
                }
            }
        }
        for (auto it : mp)
        {
            int index = DS.findUPar(it.second);
            mpp[index].push_back(it.first);
        }
        vector<vector<string>> result;
        for (auto it : mpp)
        {
            string name = accounts[it.first][0];
            sort(it.second.begin(), it.second.end());
            vector<string> temp = it.second;
            temp.insert(temp.begin(), name);
            result.push_back(temp);
        }
        return result;
    }
};
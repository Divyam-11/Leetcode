class Solution
{
public:
    long long weightedSum(vector<int> &parent, vector<int> &nums)
    {
        int n = parent.size();
        vector<vector<int>> adjList(n);
        for (int i = 1; i < n; i++)
        {
            adjList[parent[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<int> depth(n);
        int d = 1;
        int h = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                depth[node] = d;
                for (auto it : adjList[node])
                {
                    q.push(it);
                }
            }
            d++;
        }
        h = d-1;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans +  nums[i] *1LL *(1LL* h - 1LL* depth[i] + 1LL);
        }
        return ans;
    }
};
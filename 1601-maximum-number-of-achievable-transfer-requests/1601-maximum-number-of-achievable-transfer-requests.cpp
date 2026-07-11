class Solution
{
public:
    int res = 0;
    bool check(int n, vector<int> &subset, vector<vector<int>> &requests)
    {
        vector<int> mp(n);
        for (auto i : subset)
        {
            int u = requests[i][0];
            int v = requests[i][1];
            mp[u]++;
            mp[v]--;
        }
        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i] != 0)
                return false;
        }
        return true;
    }

    void subset(int n, int index, vector<vector<int>> &requests, vector<int> &cur)
    {
        if (index == requests.size())
        {
            if (check(n, cur, requests))
            {
                res = max(res, (int)cur.size());
            }
            return;
        }
        // pick
        cur.push_back(index);
        subset(n, index + 1, requests, cur);
        cur.pop_back();
        subset(n, index + 1, requests, cur);
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {

        vector<int> cur;
        subset(n, 0, requests, cur);
        return res;
    }
};
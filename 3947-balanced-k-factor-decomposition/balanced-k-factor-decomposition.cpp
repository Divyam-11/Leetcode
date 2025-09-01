class Solution
{
public:
    int min_max_diff = INT_MAX;
    vector<int> result;
    void solve(vector<int> &v, int cur, int k)
    {   
        if (v.size() == k )
        {   if(cur == 1){
            int min_v = INT_MAX;
            int max_v = INT_MIN;
            for (auto i : v)
            {
                min_v = min(min_v, i);
                max_v = max(max_v, i);
            }
            if (max_v - min_v < min_max_diff)
            {
                min_max_diff = max_v - min_v;
                result = v;
            }
        }
            return ;
        }

        for (int i = 1; i <= cur; i++)
        {
            if (cur % i != 0)
                continue;
            v.push_back(i);
            solve(v, cur / i, k);
            v.pop_back();
        }
    }
    vector<int> minDifference(int n, int k)
    {
        vector<int> v;
        solve(v, n, k);
        return result;
    }
};
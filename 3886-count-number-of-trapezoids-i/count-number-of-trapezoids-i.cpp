class Solution
{
public:
    const int MOD = 1e9+7;
    long long C(long long n, long long k)
    {   
        long long ans = n % MOD * (n-1) % MOD;
        ans = ans / 2;
        ans = ans % MOD;
        return ans;
    }
    int countTrapezoids(vector<vector<int>> &points)
    {
        map<int, long long> mp;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            mp[y]++;
        }

        long long prefix = 0;
        long long res = 0;
        for (auto i : mp)
        {
            res += (prefix%MOD * C(i.second, 2)%MOD)%MOD;
            prefix += C(i.second, 2);
        }
        return res%MOD;
    }
};
class Solution
{
public:
    long long totalScore(int hp, vector<int> &d, vector<int> &rq)
    {
        long long ans = 0;
        int n = d.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + d[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            int c = rq[i - 1] + prefix[i] - hp;
            auto it = lower_bound(prefix.begin(), prefix.end(), c);
            int index = it - prefix.begin();
            if (index + 1 > i)
                continue;
            index++;
            ans += (i - index + 1);
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target)
    {
        vector<int> res;

        long long nl = n;
        long long sum = (nl * (nl + 1)) / 2;
        if (sum < target || -sum > target)
            return {};
        if ((sum - target) % 2 != 0)
            return {};
        while (nl > 0)
        {
           
            if (sum - 2 * nl >= target)
            {
                sum -= 2 * nl;
                res.push_back(-1 * nl);
                nl--;
            }
            else
            {
                res.push_back(nl--);
            }
        }
        if (sum != target)
            return {};
        sort(res.begin(), res.end());

        return res;
    }
};
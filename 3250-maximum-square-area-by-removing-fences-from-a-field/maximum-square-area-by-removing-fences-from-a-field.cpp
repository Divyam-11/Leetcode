class Solution
{
public:
    const int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        int maxSide = 0;
        unordered_set<int> st;
        for (int i = 0; i < hFences.size(); i++)
        {
            for (int j = i + 1; j < hFences.size(); j++)
            {
                st.insert(hFences[j] - hFences[i]);
            }
        }
        for (int i = 0; i < vFences.size(); i++)
        {
            for (int j = i + 1; j < vFences.size(); j++)
            {
                int side = vFences[j] - vFences[i];
                if (st.find(side) != st.end())
                {
                    maxSide = max(maxSide, side);
                }
            }
        }
        long long area = maxSide * 1LL * maxSide;

        area = area % mod;
        if (area == 0)
            return -1;
        return (int)area;
    }
};
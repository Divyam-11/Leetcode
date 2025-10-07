class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        unordered_map<int, int> mp;
        set<int> st;
        vector<int> ans(rains.size(), 1);
        for (int i = 0; i < rains.size(); i++)
        {
            if (rains[i] == 0)
            {
                st.insert(i);
            }
            else
            {
                ans[i] = -1;
                if (mp.count(rains[i]))
                {
                    auto it = st.upper_bound(mp[rains[i]]);
                    if (it == st.end())
                        return {};
                    ans[*it] = rains[i];
                    st.erase(it);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};
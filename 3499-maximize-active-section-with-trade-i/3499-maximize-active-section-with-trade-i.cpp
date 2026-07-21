class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        char c = s[0];
        int freq = 0;
        int res = 0;
        vector<pair<char, int>> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                freq++;
            else
            {
                mp.push_back({c, freq});
                c = s[i];
                freq = 1;
            }
            if (s[i] == '1')
                res++;
        }
        mp.push_back({c, freq});
        int prev = -1;
        int curr = -1;
        int final_res = 0;
        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i].first == '0')
            {
                if (prev == -1)
                {
                    prev = mp[i].second;
                }
                else
                {
                    final_res = max(final_res, prev + mp[i].second);
                    prev = mp[i].second;
                }
            }
        }
        return final_res + res;
    }
};
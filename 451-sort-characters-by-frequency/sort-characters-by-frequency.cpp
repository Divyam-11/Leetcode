class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        set<pair<int, char>> st;
        for (auto i : mp)
        {
            st.insert({i.second * -1, i.first});
        }
        string res;
        for (auto i : st)
        {
            res += string(abs(i.first), i.second);
        }
        return res;
    }
};
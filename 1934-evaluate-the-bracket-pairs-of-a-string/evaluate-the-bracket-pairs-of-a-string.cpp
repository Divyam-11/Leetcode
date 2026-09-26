class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> mp;
        for (int i = 0; i < knowledge.size(); i++)
        {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        int i = 0;
        vector<string> st;
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (!temp.empty())
                    st.push_back(temp);
                temp.clear();
                continue;
            }
            if (s[i] == ')')
            {
                temp.push_back(s[i]);
                if (!temp.empty())
                    st.push_back(temp);
                temp.clear();
                continue;
            }

            temp.push_back(s[i]);
        }
        if (!temp.empty())
            st.push_back(temp);
        string res;
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i].back() == ')')
            {
                st[i].pop_back();
                if(mp.find(st[i]) == mp.end()) res.push_back('?');
                else
                res += mp[st[i]];
            }
            else
            {
                res += st[i];
            }
        }
        return res;
    }
};
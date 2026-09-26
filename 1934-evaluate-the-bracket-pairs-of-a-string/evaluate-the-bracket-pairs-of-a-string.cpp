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
        // vector<string> st;
        string res;
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (!temp.empty())
                    res += temp;
                temp.clear();
                continue;
            }
            if (s[i] == ')')
            {

                if (!temp.empty())
                {
                    if (mp.find(temp) == mp.end())
                    {
                        res += "?";
                    }
                    else
                        res += mp[temp];
                }
                temp.clear();
                continue;
            }

            temp.push_back(s[i]);
        }
        if (!temp.empty())
            res += temp;

        return res;
    }
};
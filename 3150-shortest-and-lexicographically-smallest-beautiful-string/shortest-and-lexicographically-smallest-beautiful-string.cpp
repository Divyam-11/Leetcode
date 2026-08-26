class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            int oneCount = 0;
            string temp;
            for (int j = i; j < s.size(); j++)
            {
                if (s[j] == '1')
                    oneCount++;
                temp.push_back(s[j]);
                if (oneCount == k)
                {
                    if (res.empty() || temp.size() < res.size())
                        res = temp;
                    else if (temp.size() == res.size())
                    {
                        res = min(res, temp);
                    }
                }
            }
        }
        return res;
    }
};
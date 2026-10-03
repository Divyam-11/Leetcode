class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        int i = 0;
        int open = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '(')
            {

                open++;
                mp[open] = j;
            }
            if (s[j] == ')')
            {
                open--;
                if(mp.find(open) != mp.end())
                res = max(res, j - mp[open]);
            }

            if (open < 0)
            {
                open = 0;
                mp.clear();
                mp[0] = j;
            }
        }
        return res;
    }
};
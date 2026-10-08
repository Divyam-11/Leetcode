class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result;
        int open = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (open != 0)
                    result.push_back('(');
                open++;
            }
            if (s[i] == ')')
            {
                if (open == 1)
                {
                    open--;
                }
                else
                {
                    result.push_back(')');
                    open--;
                }
            }
        }
        return result;
    }
};
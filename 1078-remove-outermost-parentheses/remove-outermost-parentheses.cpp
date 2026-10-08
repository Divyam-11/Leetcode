class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (!st.empty())
                    result.push_back('(');
                st.push(s[i]);
            }
            if (s[i] == ')')
            {
                if (st.size() == 1)
                {
                    st.pop();
                }
                else
                {
                    result.push_back(')');
                    st.pop();
                }
            }
        }
        return result;
    }
};
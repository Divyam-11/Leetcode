class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ')')
            {    st.push(s[i]);
            continue;}
            string temp;
            while (!st.empty() && st.top() != '(' && s[i] == ')')
            {
                temp.push_back(st.top());
                st.pop();
            }
            st.pop();
            for (int i = 0; i < temp.size(); i++)
            {
                st.push(temp[i]);
            }
        }
        string res;
        while (!st.empty())
        {
            char x = st.top();
            res.push_back(x);
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
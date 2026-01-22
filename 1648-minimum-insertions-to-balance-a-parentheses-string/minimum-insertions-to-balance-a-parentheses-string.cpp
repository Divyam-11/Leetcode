class Solution
{
public:
    int minInsertions(string s)
    {
        int ops = 0;
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {   
                cout<<"hey"<<endl;
                st.push('(');
                
            }
            else
            {
                if (i == s.size() - 1 || s[i + 1] != ')')
                {
                    ops++;
                    if(!st.empty())
                    st.pop();
                    else ops++;
                }
                else if (s[i + 1] == ')')
                {   
                    if(!st.empty())
                    st.pop();   
                    else ops++;
                    i++;
                }
            }
        }
        
        
        return ops + st.size()*2;
    }
};
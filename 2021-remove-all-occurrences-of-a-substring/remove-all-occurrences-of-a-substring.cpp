class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string st;
        for (int i = 0; i < s.size(); i++)
        {
            st.push_back(s[i]);
            if (st.size() >= part.size() && st.back() == part.back())
            {
                if (st.substr(st.size() - part.size(), part.size()) == part)
                {
                    st = st.substr(0, st.size() - part.size());
                }
            }
        }
        return st;
    }
};
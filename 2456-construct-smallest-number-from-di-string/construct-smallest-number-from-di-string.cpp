class Solution
{
public:
    string smallestNumber(string pattern)
    {
        stack<int> st;
        string result;
        for (int i = 0; i < pattern.size()+1 ; i++)
        {
            st.push(i + 1);
            while (!st.empty() && pattern[i] == 'I')
            {
                result.push_back(st.top() + '0');
                st.pop();
            }
        }
        while (!st.empty())
        {
            result.push_back(st.top() + '0');
            st.pop();
        }
        return result;
    }
};
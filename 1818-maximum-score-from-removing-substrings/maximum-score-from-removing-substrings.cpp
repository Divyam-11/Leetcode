class Solution
{
public:
    int score(string &s, char a, char b, int x)
    {
        int result = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && (st.top() == a && s[i] == b))
            {
                st.pop();
                result += x;
            }
            else
            {
                st.push(s[i]);
            }
             
        }   s = "";

            while (!st.empty())
            {
                s += st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            return result;
    }
    int maximumGain(string s, int x, int y)
    {
        int total = 0;
        if (x > y)
        {
            total += score(s, 'a', 'b', x);
            total += score(s, 'b', 'a', y);
        }
        else
        {   
            total += score(s, 'b', 'a', y);
            total += score(s, 'a', 'b', x);
            
        }
        return total;
    }
};
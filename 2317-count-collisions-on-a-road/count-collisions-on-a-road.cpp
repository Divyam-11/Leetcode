class Solution
{
public:
    int countCollisions(string directions)
    {
        int col = 0;
        stack<char> st;
        for (int i = 0; i < directions.size(); i++)
        {
            if (directions[i] == 'S')
            {
                while (!st.empty() && st.top() == 'R')
                {

                    col++;
                    st.pop();
                }
                st.push('S');
            }
            if (directions[i] == 'L')
            {
                if (!st.empty() && st.top() == 'R')
                {
                    col++;
                    while (!st.empty() && st.top() == 'R')
                    {
                        st.pop();
                        col ++;
                    }
                    st.push('S');
                }
                else if (!st.empty() && st.top() == 'S')
                {
                    st.push('S');
                    col++;
                }
            }
            if (directions[i] == 'R')
            {
                st.push('R');
            }
        }
        return col;
    }
};
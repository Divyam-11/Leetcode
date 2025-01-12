class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        if (s.size() % 2 == 1)
            return false;

        stack<int>
            unlocked_st;
        stack<int> locked_st;
        for (int i = 0; i < s.size(); i++)
        {
            if (locked[i] == '0')
            {
                unlocked_st.push(i);
            }
            else if (s[i] == '(' && locked[i] == '1')
            {
                locked_st.push(i);
            }
            else if (s[i] == ')' && locked[i] == '1')
            {
                if (!locked_st.empty())
                {
                    locked_st.pop();
                }
                else if (!unlocked_st.empty())
                {
                    unlocked_st.pop();
                }
                else
                    return false;
            }
        }
        while (!locked_st.empty() && !unlocked_st.empty() && unlocked_st.top() > locked_st.top())

        {

            unlocked_st.pop();
            locked_st.pop();
        }
        if (!locked_st.empty())
            return false;

        return true;
    }
};
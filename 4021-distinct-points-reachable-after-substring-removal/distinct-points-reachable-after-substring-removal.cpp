class Solution
{
public:
    int distinctPoints(string s, int k)
    {
        int x = 0;
        int y = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                x--;
            if (s[i] == 'U')
                y++;
            if (s[i] == 'R')
                x++;
            if (s[i] == 'D')
                y--;
        }
        int w_x = 0;
        int w_y = 0;
        for (int i = 0; i <= k - 1; i++)
        {
            if (s[i] == 'L')
                w_x--;
            if (s[i] == 'U')
                w_y++;
            if (s[i] == 'R')
                w_x++;
            if (s[i] == 'D')
                w_y--;
        }
        set<pair<int, int>> st;
        st.insert({x - w_x, y - w_y});
        for (int i = k; i < s.size(); i++)
        {
            if (s[i - k] == 'L')
                w_x++;
            if (s[i - k] == 'U')
                w_y--;
            if (s[i - k] == 'R')
                w_x--;
            if (s[i - k] == 'D')
                w_y++;
            if (s[i] == 'L')
                w_x--;
            if (s[i] == 'U')
                w_y++;
            if (s[i] == 'R')
                w_x++;
            if (s[i] == 'D')
                w_y--;
            st.insert({x - w_x, y - w_y});
        }
        return st.size();
    }
};
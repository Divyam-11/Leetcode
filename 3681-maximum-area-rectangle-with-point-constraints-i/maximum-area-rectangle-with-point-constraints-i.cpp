class Solution
{
public:
    bool validate(int x, int y, int a, int b, map<pair<int, int>, int> &mp)
    {
        if (mp[{x, b}] == 0 || mp[{a, y}] == 0)
            return false;
        int top_left_x = min(x, a);
        int top_left_y = max(y, b);
        int bottom_right_x = max(x, a);
        int bottom_right_y = min(y, b);
        set<pair<int, int>> st;
        st.insert({top_left_x, top_left_y});
        st.insert({bottom_right_x, bottom_right_y});
        st.insert({top_left_x, bottom_right_y});
        st.insert({bottom_right_x, top_left_y});
        for (int i = top_left_x; i <= bottom_right_x; i++)
        {
            for (int j = bottom_right_y; j <= top_left_y; j++)
            {
                if (st.find({i, j}) != st.end())
                    continue;
                if (mp[{i, j}])
                    return false;
            }
        }
        return true;
    }
    int maxRectangleArea(vector<vector<int>> &points)
    {
        int res = 0;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            mp[{x, y}] = 1;
        }
        for (int p = 0; p < points.size(); p++)
        {
            int x = points[p][0];
            int y = points[p][1];
            for (int i = 0; i < points.size(); i++)
            {
                if (i == p)
                    continue;
                int a = points[i][0];
                int b = points[i][1];
                int area = abs(y - b) * abs(x - a);
                if (validate(x, y, a, b, mp))
                {
                    res = max(res, area);
                }
            }
        }
        if(!res) return -1;
        return res;
    }
};
class Solution
{
public:
    bool solve(int x, int y, unordered_map<string, string> &mp, vector<string> &pyramid)
    {   
        if (x == 0)
        {
            return !mp[{pyramid[1][0], pyramid[1][1]}].empty();
        }
        string temp = mp[{pyramid[x + 1][y], pyramid[x + 1][y + 1]}];
        for (int i = 0; i < temp.size(); i++)
        {
            pyramid[x][y] = temp[i];
            if (y == x)
            {
                if (solve(x - 1, 0, mp, pyramid))
                    return true;
            }
            else
            {
                if (solve(x, y + 1, mp, pyramid))
                    return true;
            }
            pyramid[x][y] = '*';
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        unordered_map<string, string> mp;
        for (int i = 0; i < allowed.size(); i++)
        {
            mp[{allowed[i][0], allowed[i][1]}].push_back(allowed[i][2]);
        }
        vector<string> pyramid(bottom.size(), string(bottom.size(), '*'));
        pyramid.back() = bottom;
        return solve(bottom.size() - 2, 0, mp, pyramid);
    }
};
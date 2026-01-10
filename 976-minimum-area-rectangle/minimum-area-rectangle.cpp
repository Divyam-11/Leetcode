class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        int res = INT_MAX;
        set<pair<int, int>> pts;
        for (int i = 0; i < points.size(); i++)
        {
            pts.insert({points[i][0], points[i][1]});
        }
        for (int i = 0; i < points.size(); i++)
        {
            int ax = points[i][0];
            int ay = points[i][1];
            for (int j = i + 1; j < points.size(); j++)
            {
                int bx = points[j][0];
                int by = points[j][1];
                int top_leftx = min(ax, bx);
                int top_lefty = max(ay, by);
                int bot_leftx = max(ax, bx);
                int bot_lefty = min(ay, by);
                if (pts.find({top_leftx, top_lefty}) == pts.end() || pts.find({top_leftx, bot_lefty}) == pts.end() || pts.find({bot_leftx, top_lefty}) == pts.end() || pts.find({bot_leftx, bot_lefty}) == pts.end())
                    continue;
                int area = abs(ax - bx) * abs(ay - by);

                if(area != 0)
                res = min(area, res);
                
            }
        }
        if (res == INT_MAX)
            return 0;
        return res;
    }
};
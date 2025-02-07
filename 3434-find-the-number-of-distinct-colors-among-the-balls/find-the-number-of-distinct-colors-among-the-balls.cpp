class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        vector<int> result;
        unordered_map<int, int> ball_colors;
        unordered_map<int, int> colors_balls;
        for (int i = 0; i < queries.size(); i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            int prev_color = ball_colors[ball];
            colors_balls[color]++;
            ball_colors[ball] = color;
            if (prev_color != 0)
            {
                if (--colors_balls[prev_color] == 0)
                    colors_balls.erase(prev_color);
            }
            result.push_back(colors_balls.size());
        }
        return result;
    }
};
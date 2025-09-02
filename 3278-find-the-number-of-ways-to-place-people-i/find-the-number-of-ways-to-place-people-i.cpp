class Solution
{
public:
    bool check(int x1, int y1, int x2, int y2, vector<vector<int>> &points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            int p_x = points[i][0];
            int p_y = points[i][1];
            if (p_x == x1 && p_y == y1)
                continue;
            if (p_x == x2 && p_y == y2)
                continue;
            if ((p_x >= x1 && p_x <= x2) && (p_y <= y1 && p_y >= y2))
            {
                return false;
            }
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>> &points)
    {
        int count = 0;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                // a-> points[i] b-> points[j]

                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1])
                {
                    if (check(points[i][0], points[i][1], points[j][0], points[j][1], points))
                    {
                        cout<<"["<<points[i][0]<<","<<points[i][1]<<"] ";
                        cout<<"["<<points[j][0]<<","<<points[j][1]<<"]"<<endl;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
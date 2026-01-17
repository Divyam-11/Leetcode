class Solution
{
public:
    long long computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {

        long long overlap = 0;
        if (ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1)
        {
            int x1 = max(ax1, bx1);
            int y1 = max(ay1, by1);
            int x2 = min(ax2, bx2);
            int y2 = min(ay2, by2);
            int side = min(abs(y2 - y1), abs(x2 - x1));
            overlap = 1LL * side * 1LL * side;
            return overlap;
        }
        return 0;
    }
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        long long maxArea = 0;
        for (int i = 0; i < bottomLeft.size(); i++)
        {
            for (int j =i+1; j < topRight.size(); j++)
            {
                
                int ax1 = bottomLeft[i][0];
                int ay1 = bottomLeft[i][1];
                int ax2 = topRight[i][0];
                int ay2 = topRight[i][1];
                int bx1 = bottomLeft[j][0];
                int by1 = bottomLeft[j][1];
                int bx2 = topRight[j][0];
                int by2 = topRight[j][1];
                maxArea = max(maxArea, computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
            }
        }
        return maxArea;
    }
};
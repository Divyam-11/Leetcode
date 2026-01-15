class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxH = 1;
        int curRunning = 1;
        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] == hBars[i - 1]+1)
            {
                curRunning++;
                maxH = max(maxH, curRunning);
            }
            else
            {
                curRunning = 1;
            }
        }
        curRunning = 1;
        int maxV = 1;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] == vBars[i - 1]+1)
            {
                curRunning++;
                maxV = max(maxV, curRunning);
            }
            else
            {
                curRunning = 1;
            }
        }
        int side = min(maxH, maxV)+1;
        return side * side;
    }
};
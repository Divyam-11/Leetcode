class Solution
{
public:
    bool canPlace(long long mid, vector<int> &workerTimes, int mountainHeight)
    {
        long long height = 0;
        for (int w : workerTimes)
        {
            double x = sqrt(0.25 + (2.0 * mid) / w) - 0.5;
            height += (long long)floor(x);
            if (height >= mountainHeight) return true;
        }
        return height >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        long long l = 0, h = 5000050000000001, ans = -1;
        while (l <= h)
        {
            long long m = l + (h - l) / 2;
            if (canPlace(m, workerTimes, mountainHeight))
            {
                ans = m;
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};

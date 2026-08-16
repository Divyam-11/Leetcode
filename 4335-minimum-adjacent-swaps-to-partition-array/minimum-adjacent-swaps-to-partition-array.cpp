class Solution
{
public:
    long long minAdjacentSwaps(vector<int> &nums, int a, int b)
    {
        long long cost = 0;
        long long zoneB = 0;
        long long zoneC = 0;

        for (int x : nums)
        {
            if (x < a)
            {
                cost += zoneB + zoneC;
            }
            else if (x > b)
            {
                zoneC++;
            }
            else
            {
                cost += zoneC;
                zoneB++;
            }
        }

        return cost % (int)(1e9+7);
    }
};
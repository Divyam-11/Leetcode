class Solution
{
public:
    bool canMake(vector<int> &bloomDay, int m, int k, int mid)
    {
        int total_blooms = 0;
        int adjCount = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                adjCount++;
            }
            else
            {
                total_blooms += adjCount / k;
                adjCount = 0;
            }
        }
        total_blooms += adjCount / k;
        return total_blooms >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int result = -1;
        long long low = 0;
        long long high = INT_MAX;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid) == true)
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};
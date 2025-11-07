class Solution
{
public:
    bool isValid(long long mid, int r, int k, vector<long long> sweep)
    {

        long long curr_power = 0;
        for (int i = 0; i < sweep.size(); i++)
        {
            curr_power += sweep[i];
            if (curr_power < mid)
            {
                long long needed_power = mid - curr_power;
                if (needed_power > k)
                    return false;
                int ub = i + 2 * r + 1;
                sweep[i] += needed_power;
                curr_power += needed_power;
                k -= needed_power;
                if (ub < sweep.size())
                {
                    sweep[ub] += -1 * needed_power;
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int> &stations, int r, int k)
    {
        long long low = 0;
        long long ans = 0;
        long long high = 1e12;
        vector<long long> sweep(stations.size());
        for (int i = 0; i < stations.size(); i++)
        {
            int lb = i - r;
            int ub = i + r + 1;
            if (lb >= 0)
            {
                sweep[lb] += stations[i];
            }
            else
            {
                sweep[0] += stations[i];
            }
            if (ub < stations.size())
            {
                sweep[ub] += -1 * stations[i];
            }
        }
        while (low <= high)
        {
            long long mid = high - (high - low) / 2;
            if (isValid(mid, r, k, sweep))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
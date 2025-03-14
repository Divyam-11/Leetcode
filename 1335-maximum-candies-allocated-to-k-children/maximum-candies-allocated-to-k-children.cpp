class Solution
{ // returns x candies can be distributed among how many children max

    long long helper(vector<int> &candies, int maxCandies)
    {
        long long k = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            k += candies[i] / maxCandies;
        }
        return k;
    }

public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        int result = 0;
        int l = 1;
        int r = 1e9;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (helper(candies, mid) >= k)
            {
                result = max(result,mid);
                l = mid+1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return result;
    }
};
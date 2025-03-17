class Solution
{
    bool isValid(vector<int> &ranks, long long k, int cars)
    {
        long long total_cars = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            long long temp = (long long)sqrt((k / ranks[i]));
            total_cars += temp;
        }
        return total_cars >= (long long)cars;
    }

public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long result = 0;
        long long r = LLONG_MAX;
        long long l = 0;
        while (l <= r)
        {
            long long mid = l - (l - r) / 2;
            if (isValid(ranks, mid, cars))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};
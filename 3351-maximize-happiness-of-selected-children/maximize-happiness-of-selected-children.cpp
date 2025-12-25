class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long res = 0;
        for (int i = 0; i < k; i++)
        {
            int temp = max(0, happiness[i] - i);
            res += temp;
        }
        return res;
    }
};
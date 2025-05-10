class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = 0;
        long long sum2 = 0;
        int zero1 = 0;
        int zero2 = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == 0)
                zero1++;
            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] == 0)
                zero2++;
            sum2 += nums2[i];
        }
        long long min_sum1 = sum1 + zero1;
        long long min_sum2 = sum2 + zero2;
        if (min_sum1 == min_sum2)
            return min_sum1;
        else if (min_sum1 < min_sum2)
        {
            if (zero1 != 0)
                return min_sum2;
        }
        else
        {
            if (zero2 != 0)
                return min_sum1;
        }
        return -1;
        }
};
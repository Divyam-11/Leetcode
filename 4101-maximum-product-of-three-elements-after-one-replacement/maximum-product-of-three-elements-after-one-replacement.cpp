class Solution
{
public:
    long long maxProduct(vector<int> &nums)
    {
        int largest = 0;
        int second_largest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) > abs(largest))
            {
                second_largest = largest;
                largest = nums[i];
            }
            else if (abs(nums[i]) > abs(second_largest))
            {
                second_largest = nums[i];
            }
        }
        long long prod = largest * 1LL * second_largest;
        return 1e5 * abs(prod);
    }
};
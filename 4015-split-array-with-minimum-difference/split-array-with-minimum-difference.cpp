class Solution
{
public:
    long long splitArray(vector<int> &nums)
    {
        vector<long long> prefix_sum(nums.size());
        vector<bool> isLeft(nums.size(), false);
        vector<bool> isRight(nums.size(), false);
        isLeft[0] = true;
        isRight[isRight.size() - 1] = true;
        prefix_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
            if (nums[i] > nums[i - 1] && isLeft[i - 1])
                isLeft[i] = true;
        }
        cout<<endl;
        long long t_sum = prefix_sum.back();
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i + 1] < nums[i] && isRight[i + 1])
            {
                isRight[i] = true;
            }
            cout<<isRight[i]<<" ";
        }
        cout<<endl;
        long long result = LLONG_MAX;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (isLeft[i] && isRight[i + 1])
            {   

                
                long long temp = abs(t_sum - prefix_sum[i] - prefix_sum[i]);

                result = min(result, temp);
            }
        }
        
        return (result == LLONG_MAX) ? -1:result;
    }
};
class Solution
{
public:
    int getLargestOutlier(vector<int> &nums)
    {
        // vector<int> prefixSum(nums.size());
        // int total_sum = 0;
        // prefixSum[0] = nums[0];
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     prefixSum[i] = prefixSum[i - 1] + nums[i];
        //     total_sum += nums[i];
        // }

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int right_sum = total_sum - nums[i];
        //     int left_sum = 0;
        //     if (i > 0)
        //     {
        //         left_sum = prefixSum[i - 1];
        //     }
        //     int total_sum = left_sum+
        // }
        int outlier = INT_MIN;
        unordered_map<int, int> mp;
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            total_sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int cur_sum = total_sum - nums[i];
            if(cur_sum % 2 == 0){
            int temp = cur_sum / 2;
            if (nums[i] == temp)
            {
                if (mp[temp] >= 2)
                {
                    outlier = max(outlier, nums[i]);
                }
            }
            else
            {
                if (mp[temp] >= 1)
                {
                    outlier = max(outlier, nums[i]);
                }
            }
            }
        }
        return outlier;
    }
};
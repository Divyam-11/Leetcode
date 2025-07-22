class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int l = 0;
        int sum = 0;
        int result = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            freq[nums[r]]++;
            sum += nums[r];

            while (freq[nums[r]] > 1)
            {
                freq[nums[l]]--;
                sum -= nums[l];
                l++;
                
            }
            cout<<sum<<endl;
            result = max(sum, result);
        }
    
    return result;
    }
};
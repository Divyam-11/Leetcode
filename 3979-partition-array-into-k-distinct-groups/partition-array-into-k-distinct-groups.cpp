class Solution
{
public:
    bool partitionArray(vector<int> &nums, int k)
    {
        if (nums.size() % k != 0)
            return false;
        int total_groups = nums.size() / k;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
           
            if (freq[nums[i]] > total_groups)
                return false;
        }

        return true;
    }
};
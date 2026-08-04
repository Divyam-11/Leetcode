class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            largest = max(largest, nums[i]);
            smallest = min(smallest, nums[i]);
            mp[nums[i]]++;
        }
        vector<int> res;
        for (int i = smallest; i <= largest; i++)
        {
            if (mp.find(i) == mp.end())
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
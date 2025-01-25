class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<deque<int>> groups;
        unordered_map<int, int> mp; // {num,group}
        for (int i = 0; i < sorted_nums.size(); i++)
        {
            if (groups.empty() || abs(groups.back().back() - sorted_nums[i]) > limit)
            {
                groups.push_back(deque<int>());
            }
            groups.back().push_back(sorted_nums[i]);
            mp[sorted_nums[i]] = groups.size() - 1;
        }
        // {{1,2,3},{4,5}};
        vector<int> result(nums.size());
        for (int i = 0; i < result.size(); i++)
        {
            result[i] = groups[mp[nums[i]]].front();
            groups[mp[nums[i]]].pop_front();
        }
        return result;
    }
};
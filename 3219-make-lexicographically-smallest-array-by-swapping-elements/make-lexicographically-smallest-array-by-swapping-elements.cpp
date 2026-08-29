class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        vector<deque<int>> groups;
        deque<int> tempGroup;
        unordered_map<int, int> mp;
        for (int i = 0; i < temp.size(); i++)
        {
            
            if (tempGroup.empty() || abs(tempGroup.back() - temp[i]) <= limit)
            {
                tempGroup.push_back(temp[i]);
            }
            else
            {
                groups.push_back(tempGroup);
                tempGroup.clear();
                tempGroup.push_back(temp[i]);
            }
            mp[temp[i]] = groups.size();
            
        }
        if (!tempGroup.empty())
            groups.push_back(tempGroup);
        for (int i = 0; i < nums.size(); i++)
        {
            int g = mp[nums[i]];
            temp[i] = groups[g].front();
            groups[g].pop_front();
        }
        return temp;
    }
};
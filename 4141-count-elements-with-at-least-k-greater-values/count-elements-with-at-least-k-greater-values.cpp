class Solution
{
public:
    int countElements(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto i : mp)
        {
            pq.push({i.first, i.second});
        }
        int res = 0;
        int total_elements_passed = 0;
        while (!pq.empty())
        {
            int num = pq.top().first;
            int freq = pq.top().second;
            if (total_elements_passed >= k)
            {
                res +=freq;
            }
            pq.pop();
            total_elements_passed += freq;
        }
        return res;
    }
};
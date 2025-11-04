class Solution
{
public:
    int XSum(vector<int> &nums, int j, int k, int x)
    {
        unordered_map<int, int> mp;
        for (int i = j; i < j + k; i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // {freq,num}
        for (auto i : mp)
        {
            
            pq.push({i.second, i.first});
        }
        int res = 0;
        while (x-- && !pq.empty())
        {
            res += pq.top().second * pq.top().first;
            
            pq.pop();
            
        }
        
        return res;
    }
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        vector<int> res;
        for (int i = 0; i < nums.size() - k + 1; i++)
        {   
            res.push_back(XSum(nums, i, k, x));
            
        }
        return res;
    }
};
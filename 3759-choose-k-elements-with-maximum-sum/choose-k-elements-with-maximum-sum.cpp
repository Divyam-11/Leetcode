class Solution
{
public:
    vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> nums;
        for (int i = 0; i < nums1.size(); i++)
        {
            nums.push_back({nums1[i], nums2[i]});
        }

        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, long long> mp;
        vector<long long> res;
        mp[nums[0].first] = 0;
        pq.push(nums[0].second);
        long long sum = pq.top();

        for (int i = 1; i < nums1.size(); i++)
        {

            if (nums[i].first == nums[i - 1].first)
            {

                // res.push_back(res.back());
                mp[nums[i].first] = mp[nums[i - 1].first];
            }
            else
            {
                // res.push_back(sum);
                mp[nums[i].first] = sum;
            }
            pq.push(nums[i].second);
            sum += nums[i].second;
            if (pq.size() > k)
            {
                sum -= (long long)pq.top();
                pq.pop();
            }
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};

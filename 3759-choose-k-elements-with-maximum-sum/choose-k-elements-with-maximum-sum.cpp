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
        vector<long long> res;

        res.push_back(0);
        pq.push(nums[0].second);
        long long sum = pq.top();

        for (int i = 1; i < nums1.size(); i++)
        {

            if (nums[i].first == nums[i - 1].first)
            {

                res.push_back(res.back());
            }
            else
            {
                res.push_back(sum);
            }
            pq.push(nums[i].second);
            sum += nums[i].second;
            if (pq.size() > k)
            {
                sum -= (long long)pq.top();
                pq.pop();
            }
        }
        unordered_map<int, long long> mp;
        for (int i = 0; i < res.size(); i++)
        {
            mp[nums[i].first] = res[i];
        }
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = mp[nums1[i]];
        }
        return res;
    }
};
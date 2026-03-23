class Solution
{
public:
    int minCost(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]]++;
            mp[nums2[i]]++;
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
        }
        for (auto i : mp)
        {
            if (i.second % 2 == 1)
                return -1;
        }
        int ops = 0;
        for (auto i : mp)
        {
            
            int first = mp1[i.first];
            int second = mp2[i.first];
            ops += abs(first - second) / 2;
        }
        return ops/2;
    }
};
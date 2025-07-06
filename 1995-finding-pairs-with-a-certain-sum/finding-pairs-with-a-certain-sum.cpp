class FindSumPairs
{
public:
    unordered_map<int, int> mp;
    vector<int> nums1, nums2;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]]++;
        }
    }

    void add(int index, int val)
    {
        mp[nums2[index]]--;
        nums2[index] += val;
        mp[nums2[index]]++;
    }

    int count(int tot)
    {
        int result = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            result += mp[tot - nums1[i]];
        }
        return result;
    }
};
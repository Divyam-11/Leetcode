class Solution
{
public:
    int res = 0;
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int i = nums1.size() - 1;
        for (int j = nums2.size() - 1; j >= 0; j--)
        {
            while (i >= 0 && nums1[i] <= nums2[j]) 
            {
                res = max(res, (j - i));
                i--;
            }
        }
        return res;
    }
};
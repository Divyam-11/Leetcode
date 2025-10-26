class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        long long append_ops = INT_MAX;
        long long ops = 0;
        long long append_num = nums2.back();
        for (int i = 0; i < nums1.size(); i++)
        {
            ops += abs(nums1[i] - nums2[i]);
            int up = max(nums1[i], nums2[i]);
            int lb = min(nums1[i], nums2[i]);
            if (append_num <= up && append_num >= lb)
            {
                append_ops = 0;
            }
            else
            {
                long long temp = min(abs(append_num - up), abs(append_num - lb));
                append_ops = min(append_ops,temp);
            }
        }
        append_ops++;
        cout<<ops<<endl;
        ops += append_ops;
        return ops;
        }
};
class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int res = 0;
        int n = nums1.size();
        if(n == 1) return 0;
        int a = min(nums1.back(), nums2.back());
        int b = max(nums1.back(), nums2.back());
        int count_pairs_1 = 0;
        int count_pairs_2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if(nums1[i]>b || nums2[i] > b) return -1;
            int temp_count = 0;
            if (nums1[i] > a && nums1[i] <= b)
            {
                count_pairs_1++;
                temp_count++;
            }
            if (nums2[i] > a && nums2[i] <= b)
            {
                count_pairs_2++;
                temp_count++;
            }
            if (temp_count == 2)
                return -1;
        }
        if(count_pairs_1 == count_pairs_2) return count_pairs_1;
        res += min(count_pairs_1, count_pairs_2);
        if(a != b){
        if (res == count_pairs_1 && b == nums1.back())
        {
            res++;
        }
        if (res == count_pairs_2 && b == nums2.back())
        {
            res++;
        }
        }
        return res;
    }
};
class Solution
{
public:
    bool is_set(int number, int x)
    {
        return (number >> x) & 1;
    }
    int addNum(int x, vector<int> &bitcount)
    {
        int num = 0;
        for (int i = 0; i < bitcount.size(); i++)
        {
            if (is_set(x, i))
            {
                bitcount[i]++;
            }
            if (bitcount[i])
            {
                num = num | (1 << i);
            }
        }
        return num;
    }
    int remNum(int x, vector<int> &bitcount)
    {
        int num = 0;
        for (int i = 0; i < bitcount.size(); i++)
        {
            if (is_set(x, i))
            {
                bitcount[i]--;
            }
            if (bitcount[i])
            {
                num = num | (1 << i);
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int> &nums, int k)
    {   
        if(k == 0) return 1;
        int res = INT_MAX;
        int l = 0;
        vector<int> bitcount(30);
        for (int r = 0; r < nums.size(); r++)
        {
            int bitvals = addNum(nums[r], bitcount);
            
            if (bitvals >= k)
                res = min(res, r - l + 1);
            while (bitvals >= k && l <= r)
            {
                bitvals = remNum(nums[l], bitcount);
                
                l++;
                if (bitvals >= k)
                    res = min(res, r - l + 1);
            }
        }
        if(res == INT_MAX) return -1;
return res;
    }
};
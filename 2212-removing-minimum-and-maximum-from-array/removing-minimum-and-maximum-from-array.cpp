class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int minVal = INT_MAX;
        int minIdx = -1;
        int maxVal = INT_MIN;
        int maxIdx = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxIdx = i;
            }
            if (nums[i] < minVal)
            {
                minVal = nums[i];
                minIdx = i;
            }
        }
        int a = max(maxIdx, minIdx);
        int b = min(minIdx, maxIdx);
        cout<<a<<" "<<b<<endl;
        int res = min(a+1,(int)( nums.size()-b));
        res = min(res, (int)(b+1 + nums.size() - a));
        return res;
    }
};
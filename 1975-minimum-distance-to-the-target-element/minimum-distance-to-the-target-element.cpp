class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int idx = -1;
        int val = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (abs(i - start) < val)
                {
                    idx = i;
                    val = abs(i - start);
                }
            }
        }
        return val;
    }
};
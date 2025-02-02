class Solution
{
public:
    bool check(vector<int> &nums)
    {
        bool drop = false;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                if (drop)
                {
                    return false;
                }
                drop = true;
            }
        }
        return true;
    }
};
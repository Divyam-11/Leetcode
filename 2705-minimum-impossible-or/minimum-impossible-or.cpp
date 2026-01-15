class Solution
{
public:
    int minImpossibleOR(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int finding = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == finding)
            {
                finding = finding << 1;
            }
            if (nums[i] > finding)
                return finding;
        }
        return finding;
    }
};
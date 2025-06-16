class Solution
{
public:
    void replace(string &nums, char x, char y)
    {
        if (x == y)
            return;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
            {
                nums[i] = y;
            }
        }
    }
    int maxDiff(int num)
    {
        char x, y;
        y = '9';
        string nums = to_string(num);
        string nums1 = nums;
        string nums2 = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != '9')
            {
                x = nums[i];
                break;
            }
        }
        replace(nums1, x, y);
        if (nums[0] != '1')
        {
            x = nums[0];
            y = '1';
            replace(nums2, x, y);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > '1')
                {
                    x = nums[i];
                    y = '0';
                    replace(nums2, x, y);
                    break;
                }
            }
        }
        return stoi(nums1) - stoi(nums2);
    }
};
class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {   
    
        int flips1 = 0, flips2 = 0, flips3 = 0;
        int indx = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                flips1 = 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                indx = i;
                break;
            }
            if(nums[i] == nums[i-1]) return false;
        }
         
        for (int i = indx; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                flips2 = 1;
            }
            else if (nums[i] > nums[i - 1])
            {
                indx = i;
                break;
            }
            if(nums[i] == nums[i-1]) return false;
        }
        for (int i = indx; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                flips3 = 1;
            }
            else
                return false;
            if(nums[i] == nums[i-1]) return false;
        }
        return (flips1 && flips2 && flips3);
    }
};

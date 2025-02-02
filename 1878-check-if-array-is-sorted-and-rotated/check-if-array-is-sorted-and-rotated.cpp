class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)  
        {
            vector<int> temp;
            int j = i;

            // Rotate and store elements in temp
            do
            {
                temp.push_back(nums[j]);
                j = (j + 1) % n;
            } while (j != i);

            // Check if rotated array is sorted
            if (is_sorted(temp.begin(), temp.end()))
                return true;
        }

        return false;
    }
};

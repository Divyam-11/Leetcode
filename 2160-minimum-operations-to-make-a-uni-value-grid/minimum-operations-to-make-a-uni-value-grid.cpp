class Solution
{
    int moves(vector<int> &nums, int x, int target)
    {
        int operations = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            operations += (abs(nums[i] - target) / x);
        }
        return operations;
    }

public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        // assumption : the univalued number belongs to the grid
        // diff between any two number less than x return -1
        // check median
        vector<int> nums;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if ((nums[i] - nums[i - 1]) % x != 0)
                return -1;
        }
        int result = moves(nums, x, nums[nums.size() / 2]);

        return result;
    }
};
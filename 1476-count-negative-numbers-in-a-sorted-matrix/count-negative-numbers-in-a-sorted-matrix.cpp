class Solution {

private:
int binary(vector<int> &nums){
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] >= 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return nums.size() - low;
}
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){

        ans+=binary(grid[i]);
        }
        return ans;
    }
};
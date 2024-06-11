using namespace std;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long result = LLONG_MAX;
        long long upper_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long lower_sum = accumulate(grid[1].begin(), grid[1].end(), 0LL);
        vector<long long> prefRow1(grid[0].begin(), grid[0].end());
        vector<long long> prefRow2(grid[1].begin(), grid[1].end());
        
        for (int i = 1; i < grid[0].size(); i++) {
            prefRow1[i] += prefRow1[i - 1];
            prefRow2[i] += prefRow2[i - 1];
        }
        
        for (int i = 0; i < grid[0].size(); i++) {
            long long top = upper_sum - prefRow1[i];
            long long bottom = (i != 0) ? prefRow2[i - 1] : 0;
            long long second_robot = max(top, bottom);
            result = min(result, second_robot);
        }
        
        return result;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += i;
        }

        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        for(int i = 2; i <= n; i++) {
            nums[i] = i + nums[i - 1];
        }

        for(int i = 1; i <= n; i++) {
            if(nums[i - 1] == sum - nums[i]) { // Check the sum to the left and to the right
                return i;
            }
        }
        return -1; // No pivot integer found
    }
};

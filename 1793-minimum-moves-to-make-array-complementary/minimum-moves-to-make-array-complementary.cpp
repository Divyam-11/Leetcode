class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        vector<int> temp(2 * limit + 2, 0);

        int n = nums.size();

        for (int i = 0; i < n / 2; i++) {

            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            temp[2] += 2;

            temp[a + 1] -= 1;

            temp[a + b] -= 1;

            temp[a + b + 1] += 1;

            temp[limit + b + 1] += 1;
        }

        int minOp = INT_MAX;
        int currOp = 0;

        for (int i = 2; i <= 2 * limit; i++) {

            currOp += temp[i];

            minOp = min(minOp, currOp);
        }

        return minOp;
    }
};
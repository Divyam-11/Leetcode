class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)
            return n;  
        if (n == 3)
            return 4; 

        return pow(2, floor(log2(n) + 1));  
    }
};
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        long ans = 0;
        bool negative = false;
        if (x < 0)
            negative = true;
        x = abs(x);
        while (x > 0) {
            int temp = x % 10;

            ans = ans * 10 + temp;
            if (ans > INT_MAX)
                return 0;
            x /= 10;
        }
        if (negative)
            return -1 * ans;
        else
            return ans;
    }
};
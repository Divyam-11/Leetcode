class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;

        if (n == 0)
            digits.push_back(0);

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        long long x = 0;

        for (int d : digits) {
            if (d != 0)
                x = x * 10 + d;
        }

        long long sum = 0;
        long long temp = x;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        return x * sum;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool neg = false;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            neg = true;
            i++;
        }
        if (s[i] == '+') {
            if (!neg)
                i++;
            else
                return 0;
        }

        long long num = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            if (neg && (num * -1) <= INT_MIN) {
                return INT_MIN;
            } else if (!neg && num >= INT_MAX)
                return INT_MAX;
            num *= 10;
            num += s[i] - '0';
            i++;
        }
        if (neg && (num * -1) <= INT_MIN) {
            return INT_MIN;
        } else if (!neg && num >= INT_MAX)
            return INT_MAX;
        if (neg) {
            num *= -1;
        }
        return num;
    }
};
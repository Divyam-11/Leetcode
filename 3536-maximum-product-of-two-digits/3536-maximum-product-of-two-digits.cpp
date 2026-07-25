class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n>0){
            int digit = n % 10;
            n = n / 10;
            digits.push_back(digit);
        }
        sort(digits.begin(),digits.end(),greater<int>());
        return digits[0] * digits[1];
    }
};
class Solution{
    public:
vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size()-1; i >=0 ; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
        }

        reverse(digits.begin(), digits.end());
        digits.push_back(1);
        reverse(digits.begin(), digits.end());

        return digits;
    }
};
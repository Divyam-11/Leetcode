class Solution
{
public:
    int minOperations(string s) {
        int res = 0;
        for (char c : s) {
            res = max(res, ('a' + 26 - c) % 26);
        }
        return res;
    }
};
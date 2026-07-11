class Solution
{
public:
    void solve(int index, string digits, string &curr, vector<string> &res, vector<string> &str)
    {
        if (index == digits.size())
        {
            res.push_back(curr);
            return;
        }
        int digit = digits[index] - '0';
        for (int i = 0; i < str[digit - 2].size(); i++)
        {
            curr.push_back(str[digit - 2][i]);
            solve(index + 1, digits, curr, res, str);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> str = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
            };
        vector<string> res;
        string curr;
        solve(0, digits, curr, res, str);
        return res;
    }
};
class Solution
{
    vector<string> result;
    unordered_map<char, std::string> key = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

private:
    void func(string &digits, unordered_map<char, string> &key, int index, string &answer)
    {
        if (index == digits.size())
        {
            result.push_back(answer);
            return;
        }
        string temp = key[digits[index]];
        for (char i : temp)
        {
            // pick
            // recurse
            // backtrack
            answer.push_back(i);
            func(digits, key, index + 1, answer);
            answer.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        string ans;
        func(digits, key, 0, ans);
        return result;
    }
};
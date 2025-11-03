class Solution
{
public:
    string toBinary(int n)
    {
        if (n == 0)
            return "0";
        string s;
        while (n > 0)
        {
            s.push_back((n & 1) + '0');
            n >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int decimal(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            res = res * 2 + (s[i] - '0');
        }
        return res;
    }
    int maxGoodNumber(vector<int> &nums)
    {
        string a = toBinary(nums[0]);
        string b = toBinary(nums[1]);
        string c = toBinary(nums[2]);
        return max({decimal(a + b + c),
                    decimal(a + c + b),
                    decimal(b + a + c),
                    decimal(b + c + a),
                    decimal(c + a + b),
                    decimal(c + b + a)});
    }
};
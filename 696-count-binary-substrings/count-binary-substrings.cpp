class Solution
{
public:
    int countBinarySubstrings(string s)

    {
        int res = 0;
        int i = 0;
        while (i < s.size())
        {
            int oneCount = 0;
            int zeroCount = 0;
            while (i < s.size() && s[i] == '0')
            {

                i++;
                zeroCount++;
            }
            while (i < s.size() && s[i] == '1')
            {
                i++;
                oneCount++;
            }
            res += min(oneCount, zeroCount);
        }
        i = 0;
        reverse(s.begin(), s.end());
        while (i < s.size())
        {
            int oneCount = 0;
            int zeroCount = 0;
            while (i < s.size() && s[i] == '0')
            {

                i++;
                zeroCount++;
            }
            while (i < s.size() && s[i] == '1')
            {
                i++;
                oneCount++;
            }
            res += min(oneCount, zeroCount);
        }
        return res;
    }
};
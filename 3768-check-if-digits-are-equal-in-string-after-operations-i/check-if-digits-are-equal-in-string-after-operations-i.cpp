class Solution
{
public:
    bool hasSameDigits(string s)
    {
        while (s.size() != 2)
        {
            string temp;
            for (int i = 0; i < s.size() - 1; i++)
            {
                int a = s[i];
                int b = s[i + 1];
                int c = (a + b) % 10;
                temp.push_back(c + '0');
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};
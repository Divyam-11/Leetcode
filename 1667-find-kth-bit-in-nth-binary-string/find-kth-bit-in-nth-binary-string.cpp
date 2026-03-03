class Solution
{
public:
    string invert(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '0')
            {
                s[i] = '1';
            }
            else
            {
                s[i] = '0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k)
    {
        string s = "0";
        int i = 1;
        while (i <= 20 && s.size() <=k )
        {
            string temp = invert(s);
            reverse(temp.begin(), temp.end());
            s = s + "1" + temp;
            i++;
        }
        return s[k-1];
    }
};
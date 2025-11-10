class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            // int sum = (a[i] - '0') + (b[i] - '0') + carry;
            int sum = carry;
            if (i >= 0)
            {
                sum += (a[i] - '0');
            }
            if (j >= 0)
            {
                sum += (b[j] - '0');
            }
            if (sum >= 2)
            {
                carry = 1;
            }
            else
                carry = 0;
            sum = sum % 2;
            result.push_back((char)sum + '0');
            i--;
            j--;
        }
        if (carry == 1)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
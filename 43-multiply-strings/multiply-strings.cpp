class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int sum = 0;
            if (i >= 0)
            {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += num2[j] - '0';
                j--;
            }
            sum += carry;
            result = result + to_string(sum % 10);
            carry = sum / 10;
        }
        if (carry)
        {
            result += to_string(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string mul(string &num1, char num2)
    {   if(num2 == '0') return "0";
        string result = "";
        int i = num1.size() - 1;
        int carry = 0;
        while (i >= 0)
        {
            int prod = (num1[i] - '0') * (num2 - '0') + carry;
            result += to_string(prod % 10);
            carry = prod / 10;
            i--;
        }
        if (carry)
        {
            result += to_string(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string multiply(string num1, string num2)
    {
        int i = num2.size() - 1;
        string final_result = "";
        while (i >= 0)
        {
            string temp = mul(num1, num2[i]);
            int count = num2.size() - 1 - i;
            while (count)
            {
                temp.push_back('0');
                count--;
            }
            final_result = addStrings(final_result, temp);
            i--;
        }
        int x = 0;
        while(final_result[x] == '0' && x < final_result.size()-1){
            x++;
        }
        
        return final_result.substr(x);
    }
};
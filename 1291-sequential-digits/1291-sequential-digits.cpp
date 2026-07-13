class Solution
{
public:
    void handleIncrement(string &str)
    {
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] == '9')
            {
                str.push_back('0');
                str[0] = '1';
                for (int i = 1; i < str.size(); i++)
                {
                    str[i] = '0';
                }
                handleIncrement(str);
                break;
            }
            str[i] = str[i - 1] + 1;
        }
    }
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> result;
        string l = to_string(low);
        for (int i = 1; i < l.size(); i++)
        {
            l[i] = l[i - 1] + 1;
        }
        while (stoi(l) < low && stoi(l) <= 123456789 && l.size() <= 9)
        {
            l[0]++;
            handleIncrement(l);
        }
        while (stoi(l) <= high && stoi(l) <= 123456789 && l.size() <= 9)
        {

            result.push_back(stoi(l));
            l[0]++;
            handleIncrement(l);
        }
        return result;
    }
};
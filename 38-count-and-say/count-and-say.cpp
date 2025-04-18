class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string n_1 = countAndSay(n - 1);
        string ans;
        char last_num = '*';
        int freq = 0;
        for (int i = 0; i < n_1.size(); i++)
        {
            if (last_num == '*')
            {
                last_num = n_1[i];
                freq++;
            }
            else if (last_num == n_1[i])
            {
                freq++;
            }
            else if (last_num != n_1[i])
            {
                
                ans += to_string(freq);
                ans.push_back(last_num);
                freq = 1;
                last_num = n_1[i];
            }
        }
                
                ans += to_string(freq);
                ans.push_back(last_num);
        return ans;
    }
};
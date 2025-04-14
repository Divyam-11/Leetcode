class Solution
{
public:
    string smallestPalindrome(string s)
    {
        string ans = "";
        vector<int> freq(26);
        int total_freq = 0;
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
            total_freq++;
        }
        cout<<"hi"<<endl;
        while (total_freq > 1)
        {

            for (int i = 0; i < 26; i++)
            {
                if (freq[i] > 1)
                {
                    ans.push_back(i + 'a');
                    freq[i] -= 2;
                    total_freq -= 2;
                    break;
                }
            }
        }
        cout<<"hi"<<endl;
        string temp = ans;
        reverse(temp.begin(), temp.end());
        if (total_freq == 1)
        {
            for (int i = 0; i < 26; i++)
            {
                if (freq[i])
                {
                    ans.push_back(i + 'a');
                }
            }
        }
        ans += temp;
        cout<<"hi"<<endl;
        return ans;
    }
};
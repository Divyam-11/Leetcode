class Solution
{
public:
    int longestBalanced(string s)
    {
        int result = 1;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> freq(26);
            int max_freq = 0;
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'a']++;
                max_freq = max(max_freq, freq[s[j] - 'a']);
                bool isBalanced = true;
                for (int k = 0; k < freq.size(); k++)
                {
                    if (freq[k] != 0 && freq[k] != max_freq)
                    {
                        isBalanced = false;
                        break;
                    }
                }
                if (isBalanced)
                {
                    result = max(result, (int)(j-i+1));
                }
            }
            bool isBalanced = true;
        }
        return result;
    }
};
class Solution
{
public:
    bool isValid(vector<int> &freq, vector<int> &word2_freq)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] < word2_freq[i])
                return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2)
    {
        vector<int> freq(26);
        vector<int> word2_freq(26);
        long long result = 0;
        for (int i = 0; i < word2.size(); i++)
        {
            word2_freq[word2[i] - 'a']++;
        }
        int l = 0;
        for (int r = 0; r < word1.size(); r++)
        {
            freq[word1[r] - 'a']++;
            while (l <= r && isValid(freq, word2_freq))
            {
                result += word1.size() - r;
                freq[word1[l]-'a']--;
                l++;
            }

            
        }
        return result;
    }
};
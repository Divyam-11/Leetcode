class Solution
{
public:
    bool isValid(vector<int> &freq, vector<int> &word2_freq)
    {
        for (int i = 0; i < 52; i++)
        {
            if (freq[i] < word2_freq[i])
                return false;
        }
        return true;
    }
    string minWindow(string word1, string word2)
    {
        vector<int> freq(52);
        vector<int> word2_freq(52);
        int res_idx = INT_MAX;
        int res_size = INT_MAX;

        for (int i = 0; i < word2.size(); i++)
        {
            if (word2[i] >= 'A' && word2[i] <= 'Z')
                word2_freq[word2[i] - 'A' + 26]++;
            else
                word2_freq[word2[i] - 'a']++;
        }
        int l = 0;
        for (int r = 0; r < word1.size(); r++)
        {
            if (word1[r] >= 'A' && word1[r] <= 'Z')
                freq[word1[r] - 'A' + 26]++;
            else
                freq[word1[r] - 'a']++;
            while (l <= r && isValid(freq, word2_freq))
            {
                int win_size = r - l + 1;
                if (win_size < res_size)
                {
                    res_size = win_size;
                    res_idx = l;
                }
                if (word1[l] >= 'A' && word1[l] <= 'Z')
                    freq[word1[l] - 'A' + 26]--;
                else
                    freq[word1[l] - 'a']--;
                l++;
            }
        }
        if (res_idx == INT_MAX)
            return "";
        return word1.substr(res_idx, res_size);
    }
};
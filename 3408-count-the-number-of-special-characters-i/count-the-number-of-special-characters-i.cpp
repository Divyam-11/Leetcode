class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<int> upperCase(26);
        vector<int> lowerCase(26);
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                lowerCase[word[i] - 'a']++;
            }
            else
            {
                upperCase[word[i] - 'A']++;
            }
        }
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (upperCase[i] && lowerCase[i])
                res++;
        }
        return res;
    }
};
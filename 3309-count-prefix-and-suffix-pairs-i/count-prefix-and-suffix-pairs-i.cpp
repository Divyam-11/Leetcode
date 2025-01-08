class Solution
{
public:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        if (str1.size() > str2.size())
            return false;
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i])
                return false;
        }
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[str2.size() - str1.size() + i])
                return false;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string> &words)
    {
        int result = 0;
        for (int i = 1; i < words.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPrefixAndSuffix(words[j], words[i]))
                {
                    result++;
                }
            }
        }
        return result;
    }
};
class Solution
{
public:
    bool exists(string str, int index, string &pattern)
    {
        if (index + pattern.size() > str.size())
            return false;

        for (int i = 0; i < pattern.size(); i++)
        {
            if (str[index + i] != pattern[i])
                return false;
        }
        return true;
    }

    int numOfStrings(vector<string> &patterns, string word)
    {
        int res = 0;

        for (int i = 0; i < patterns.size(); i++)
        {
            for (int j = 0; j < word.size(); j++)
            {
                if (word[j] == patterns[i][0])
                {
                    if (exists(word, j, patterns[i]))
                    {
                        res++;
                        break;
                    }
                }
            }
        }

        return res;
    }
};
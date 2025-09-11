class Solution
{
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s)
    {
        vector<int> freq(52);
        for (auto &i : s)
        {
            if (isVowel(i))
            {
                if (i < 'Z')
                {
                    freq[i - 'A']++;
                }
                else
                {
                    freq[i - 'a' + 26]++;
                }
                i = '*';
            }
        }

        int map_iter = 0;
        for (auto &i : s)
        {
            if (i == '*')
            {
                while (freq[map_iter] == 0 && map_iter < 52)
                {
                    map_iter++;
                }
                if (map_iter < 26)
                {
                    i = map_iter + 'A';
                }
                else
                {
                    i = map_iter - 26 + 'a';
                }
                freq[map_iter]--;
            }
        }
        return s;
    }
};
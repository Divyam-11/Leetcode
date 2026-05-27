#pragma GCC optimize("Ofast,unroll-loops")

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<int> mp(26, -1);
        for (int i = 0; i < word.size(); i++)
        {
            if (islower(word[i]))
            {
                if (mp[word[i] - 'a'] == -1)
                    mp[word[i] - 'a'] = 0;
                else if (mp[word[i] - 'a'] == 1)
                    mp[word[i] - 'a'] = -2;
            }
            else
            {
                if (mp[word[i] - 'A'] == -1)
                    mp[word[i] - 'A'] = -2;
                else if (mp[word[i] - 'A'] == 0)
                    mp[word[i] - 'A'] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] == 1)
                res++;
        }
        return res;
    }
};

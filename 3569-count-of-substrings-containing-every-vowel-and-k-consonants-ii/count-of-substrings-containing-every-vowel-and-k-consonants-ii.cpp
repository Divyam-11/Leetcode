class Solution
{
public:
    long long AtLeastK(string word, int k)
    {
        long long result = 0;
        unordered_map<char, int> mp;
        int c_count = 0;
        int l = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')

            {
                mp[word[i]]++;
            }
            else
                c_count++;
            while (mp.size() == 5 && c_count >= k)
            {
                result += word.size() - i;
                if (word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u')
                {
                    mp[word[l]]--;
                    if (mp[word[l]] == 0)
                        mp.erase(word[l]);
                }
                else
                    c_count--;
                l++;
            }
        }
        return result;
    }

    long long countOfSubstrings(string word, int k)
    {
        return AtLeastK(word, k) - AtLeastK(word, k + 1);
    }
};
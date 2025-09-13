class Solution
{
public:
    int maxFreqSum(string s)
    { /*
      a->0
      e->4
      i->8
      o->
      */
        int maxVowel = 0;
        int maxConstonent = 0;
        vector<int> freq(26);
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (i + 'a' == 'a' || i + 'a' == 'e' || i + 'a' == 'i' || i + 'a' == 'o' || i + 'a' == 'u')
                maxVowel = max(maxVowel, freq[i]);
            else
                maxConstonent = max(maxConstonent, freq[i]);
        }
        return maxVowel + maxConstonent;
    }
};
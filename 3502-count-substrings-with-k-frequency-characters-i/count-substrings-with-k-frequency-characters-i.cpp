class Solution
{
public:
    bool isValid(vector<int> &freq, int &k)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] >= k)
                return true;
        }
        return false;
    }
    int numberOfSubstrings(string s, int k)
    {
        int count = 0;
        vector<int> freq(26);
        int l = 0;
        for (int r = 0; r < s.size(); r++)
        {
            freq[s[r]-'a']++;
            while (l <= r && isValid(freq, k))
            {
                count += s.size() - r;
                freq[s[l]-'a']--;
                l++;
            }
        }
        return count;
    }
};

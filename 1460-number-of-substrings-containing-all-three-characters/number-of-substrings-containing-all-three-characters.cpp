class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int count = 0;
    vector<int> freq(3);
    int l = 0;
    for (int i = 0; i < s.size(); i++)
    {
      freq[s[i] - 'a']++;
      while (freq[0] && freq[1] && freq[2] && l < i)
      {
        count += s.size() - i;

        freq[s[l] - 'a']--;
        l++;
      }
    }
    return count;
  }
};
class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {
        vector<int> freq1(26);
        vector<int> freq2(26);
        for (int i = 0; i < s1.size(); i += 2)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        if (freq1 != freq2)
            return false;
                vector<int> freq3(26);
        vector<int> freq4(26);
        for (int i = 1; i < s1.size(); i += 2)
        {
            freq3[s1[i] - 'a']++;
            freq4[s2[i] - 'a']++;

        }
        if (freq3 != freq4)
            return false;
        return true;
    }
};
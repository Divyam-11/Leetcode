class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        vector<int> s1_map(26);
        for (int i = 0; i < s1.size(); i++)
        {
            s1_map[s1[i] - 'a']++;
        }
        vector<int> s2_map(26);

        for (int i = 0; i < s1.size(); i++)
        {
            s2_map[s2[i] - 'a']++;
        }
        if (s2_map == s1_map)
            return true;
        int l = 0;
        for (int i = s1.size(); i < s2.size(); i++)
        {
            s2_map[s2[l] - 'a']--;
            s2_map[s2[i] - 'a']++;
            if (s2_map == s1_map)
                return true;
            l++;
        }
        return false;
    }
};
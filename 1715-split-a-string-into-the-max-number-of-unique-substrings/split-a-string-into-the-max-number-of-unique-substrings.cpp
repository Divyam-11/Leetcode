class Solution
{
    void solve(int index, string s, set<string> &mp, int &max_result)
    {
        if (index >= s.size())
        {
            max_result = max(max_result, (int)mp.size());
            return;
        }
        string str;
        for (int i = index; i < s.size(); i++)
        {
            str += s[i];
            if (mp.find(str) != mp.end())
                continue;
            mp.insert(str);

            solve(i + 1, s, mp, max_result);
            mp.erase(str);
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        set<string> mp;
        int max_result = -1;

        string subarray;
        solve(0, s, mp, max_result);
        return max_result;
    }
};
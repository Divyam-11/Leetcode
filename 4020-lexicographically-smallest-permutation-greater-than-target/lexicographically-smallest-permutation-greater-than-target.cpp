class Solution
{
public:
    string answer;
    void solve(int index, string temp, string &target, unordered_map<char, int> &s_freq, bool flag)
    {
        if (!answer.empty())
            return;
        if (temp.size() == target.size())
        {
            if (temp > target)
                answer = temp;
            return;
        }
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (flag == false && i < target[index])
                continue;
            if (s_freq[i])
            {
                s_freq[i]--;
                temp.push_back(i);
                if (flag || i > target[index])
                {
                    solve(index + 1, temp, target, s_freq, true);
                }
                else
                    solve(index + 1, temp, target, s_freq, flag);
                temp.pop_back();
                s_freq[i]++;
            }
        }
    }
    string lexGreaterPermutation(string s, string target)
    {
        unordered_map<char, int> s_freq;
        for (int i = 0; i < s.size(); i++)
        {
            s_freq[s[i]]++;
        }
        string temp;
        bool flag = false;
        solve(0, temp, target, s_freq, flag);
        return answer;
    }
};
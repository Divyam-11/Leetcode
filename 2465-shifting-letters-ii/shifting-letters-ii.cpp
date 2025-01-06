class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        bool addition = false;

        vector<int> netShifts(s.size()+1);
        for (int i = 0; i < shifts.size(); i++)
        {
            int direction = 0;
            addition = shifts[i][2];
            if (addition)
            {
                direction = 1;
            }
            else
                direction = -1;
            netShifts[shifts[i][0]] += direction;
            netShifts[shifts[i][1] + 1] -= direction;
        }
        int cummulative_sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cummulative_sum += netShifts[i];
            int netShift = (s[i] - 'a' + cummulative_sum) % 26;
            if (netShift < 0)
            {
                netShift += 26;
            }
            s[i] = 'a' + netShift;
        }
        return s;
    }
};
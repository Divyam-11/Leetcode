class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size();
        int m = mana.size();
        vector<long long> last_brew(n); // done by time
        long long time = 0;
        for (int i = 0; i < n; i++)
        {
            last_brew[i] = time + skill[i] * mana[0];
            time = last_brew[i];

        }
        for (int i = 1; i < m; i++)
        {
            long long start_time = 0;
            long long cur_time = 0;
            for (int j = 0; j < n; j++)
            {
                start_time = max(start_time, last_brew[j] - cur_time);
                cur_time += skill[j] * mana[i];
            }
            for (int j = 0; j < n; j++)
            {
                last_brew[j] = start_time + skill[j] * mana[i];
                start_time = last_brew[j];
            }
        }
        return last_brew.back();
    }
};
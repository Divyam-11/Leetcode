class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        
        int res = 0;
        int prev = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            int light_count = 0;
            for (int j = 0; j < bank[0].size(); j++)
            {
                if (bank[i][j] == '1')
                    light_count++;
            }
            if (light_count)
            {
                res += prev * light_count;
                prev = light_count;
            }
        }
        return res;
    }
};
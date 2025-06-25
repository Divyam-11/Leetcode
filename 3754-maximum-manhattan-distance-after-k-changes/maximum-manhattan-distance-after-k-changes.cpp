class Solution
{
public:
    int maxDistance(string str, int k)
    {
        int n = 0;
        int s = 0;
        int e = 0;
        int w = 0;
        int answer = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'N')
            {
                n++;
            }
            if (str[i] == 'S')
            {
                s++;
            }
            if (str[i] == 'E')
            {
                e++;
            }
            if (str[i] == 'W')
            {
                w++;
            }
            int before_man_distance = abs(n - s) + abs(w - e);
            
            int total_buffer_addition = 0;
            if (n > s)
            {
                total_buffer_addition += s;
            }
            else
            {
                total_buffer_addition += n;
            }
            if (e > w)
            {
                total_buffer_addition += w;
            }
            else
            {
                total_buffer_addition += e;
            }
            
            int additions = min(total_buffer_addition, k);
            answer = max(answer, before_man_distance + 2 * additions);
        }

        return answer;
    }
};
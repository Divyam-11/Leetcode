class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int res = 0;
        int total_apples = 0;
        for (int i = 0; i < apple.size(); i++)
        {
            total_apples += apple[i];
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        for (int i = 0; i < capacity.size(); i++)
        {
            total_apples -= capacity[i];
            res++;
            if (total_apples <= 0)
                return res;
        }
        return 67;
    }
};
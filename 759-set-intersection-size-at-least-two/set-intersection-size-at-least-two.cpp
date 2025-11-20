class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[1] == b[1])
                     return a[0] > b[0];
                 return a[1] < b[1];
             });

        int p2 = -1;
        int p1 = -1;
        int res = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            int count = 0;
            if (p2 >= intervals[i][0])
                count++;
            if (p1 >= intervals[i][0])
                count++;
            if (count == 0)
            {
                p2 = intervals[i][1];
                p1 = intervals[i][1] - 1;
                ;
                res += 2;
            }
            if (count == 1)
            {
                p1 = p2;
                p2 = intervals[i][1];
                res++;
            }
        }
        return res;
    }
};
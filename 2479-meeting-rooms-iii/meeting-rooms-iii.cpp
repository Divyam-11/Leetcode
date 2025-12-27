class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<int> rooms(n);
        for (int i = 0; i < n; i++)
        {
            free.push(i);
        }
        for (int i = 0; i < meetings.size(); i++)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];
            while (!pq.empty() && (pq.top().first <= start))
            {
                free.push({pq.top().second});
                pq.pop();
            }
            if (!free.empty())
            {
                pq.push({end, free.top()});
                rooms[free.top()]++;
                free.pop();
            }
            else
            {
                int duration = end - start;
                auto temp = pq.top();
                pq.pop();
                pq.push({temp.first + duration, temp.second});
                rooms[temp.second]++;
            }
        }
        int res = 0;
        int res_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (rooms[i] > res)
            {
                res = rooms[i];
                res_index = i;
            }
        }
        return res_index;
    }
};
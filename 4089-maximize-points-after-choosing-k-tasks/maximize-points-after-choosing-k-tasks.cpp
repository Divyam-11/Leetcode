class Solution
{
public:
    long long maxPoints(vector<int> &technique1, vector<int> &technique2, int k)
    {
        vector<int> taken(technique1.size());
        long long pts = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < technique1.size(); i++)
        {
            pq.push({technique1[i] - technique2[i],
                     i});
        }
        while (k--)
        {
            taken[pq.top().second] = 1;
            pts += technique1[pq.top().second];
            pq.pop();
        }
        for (int i = 0; i < technique1.size(); i++)
        {
            if (!taken[i])
            {
                pts += max(technique1[i], technique2[i]);
            }
        }
        return pts;
    }
};
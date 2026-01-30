class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int l = 0;
        int r = costs.size() - 1;

        int low = 0;
        int high = r;
        while (l < candidates && l < costs.size())
        {
            pq.push({costs[l], l});
            low = l;
            l++;
        }
        int i = 0;
        while (i < candidates && r >= l && r > 0)
        {

            pq.push({costs[r], r});
            high = r;
            i++;
            r--;
        }

        long long cost = 0;
        while (k--)
        {
            cost += pq.top().first;

            int idx = pq.top().second;
            cout << pq.top().first << endl;
            pq.pop();
            if (idx < l)
            {
                if (l <= r)
                {

                    pq.push({costs[l], l});
                    l++;
                }
            }
            else
            {
                if (l <= r)
                {

                    pq.push({costs[r], r});
                    r--;
                }
            }
        }
        return cost;
    }
};
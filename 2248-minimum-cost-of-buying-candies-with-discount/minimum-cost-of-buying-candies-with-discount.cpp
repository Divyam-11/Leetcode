class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {   
        
        priority_queue<int> pq(cost.begin(), cost.end());
        int c = 0;
        while (pq.size() >= 2)
        {
            c += pq.top();
            pq.pop();
            c += pq.top();
            pq.pop();
            if (!pq.empty())
            {
                pq.pop();
            }
        }
        if(pq.size() == 1) c+=pq.top();
        return c;
    }
};
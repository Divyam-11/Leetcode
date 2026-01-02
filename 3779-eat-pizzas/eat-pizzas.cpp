class Solution
{
public:
    long long maxWeight(vector<int> &pizzas)
    {
        long long weight = 0;
        priority_queue<int> pq;
        for (int i = 0; i < pizzas.size(); i++)
        {
            pq.push(pizzas[i]);
        }
        int days = pizzas.size() / 4;
        int odd_days = (days+1)/2;
        int even_days = days/2;
        while(odd_days--){
            weight+=pq.top();
            pq.pop();
        }
        while(even_days--)
        {
            int largest = pq.top();
            pq.pop();
            weight+=pq.top();
            pq.pop();
        }
        return weight;
    }
};
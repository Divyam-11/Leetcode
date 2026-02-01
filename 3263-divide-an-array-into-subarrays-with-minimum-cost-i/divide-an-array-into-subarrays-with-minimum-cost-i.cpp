class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i = 1; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        int cost = nums[0];
        cost += pq.top();
        pq.pop();
        cost += pq.top();
        return cost;
    }
};
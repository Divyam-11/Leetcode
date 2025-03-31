class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        long long minSum = 0;
        long long maxSum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
        for (int i = 1; i < weights.size(); i++)
        {
            maxHeap.push(weights[i] + weights[i - 1]);
            minHeap.push(weights[i] + weights[i - 1]);
        }
        while (k != 1)
        {
            maxSum += maxHeap.top();
            maxHeap.pop();
            minSum += minHeap.top();
            minHeap.pop();
            k--;
        }
        return maxSum - minSum;
    }
};
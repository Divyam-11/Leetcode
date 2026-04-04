class MedianFinder
{
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        pq2.push(num);
        if (!pq1.empty() && pq1.top() > pq2.top())
        {
            int x = pq1.top();
            int y = pq2.top();
            pq1.pop();
            pq2.pop();
            pq1.push(y);
            pq2.push(x);
        }
        if (pq1.size() < pq2.size())
        {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    double findMedian()
    {
        if (pq1.size() == pq2.size())
        {
            double a = pq1.top();
            double b = pq2.top();
            return (a + b) / 2;
        }
        else
            return (double)pq1.top();
    }
};
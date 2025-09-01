class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        auto cmp = [](pair<int,int> a, pair<int,int> b) {
            double a_gain = (double)(a.first + 1) / (a.second + 1) - (double)a.first / a.second;
            double b_gain = (double)(b.first + 1) / (b.second + 1) - (double)b.first / b.second;
            return a_gain < b_gain; // max-heap
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < classes.size(); i++)
        {
            pq.push({classes[i][0], classes[i][1]});
        }
        while (extraStudents)
        {
            auto temp = pq.top();
            pq.pop();
            temp.first++;
            temp.second++;
            pq.push({temp.first, temp.second});
            extraStudents--;
        }
        double final_average = 0;
        while (!pq.empty())
        {
            final_average += pq.top().first / (double)pq.top().second;
            pq.pop();
        }
        return final_average / (double)classes.size();
    }
};
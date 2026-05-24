class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        priority_queue<pair<int, int>> oddpq;
        priority_queue<pair<int, int>> evenpq;
        for (int x = 0; x < k; x++)
        {
            int odd_dis = 0;
            int eve_dis = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                int rem = nums[i] % k;
                if (i % 2)
                {
                    odd_dis += min({abs(rem - x),
                                    abs(rem + k - x),
                                    abs(rem - k - x)});
                }
                else
                {
                    eve_dis += min({abs(rem - x),
                                    abs(rem + k - x),
                                    abs(rem - k - x)});
                }
            }
            oddpq.push({-odd_dis, x});
            evenpq.push({-eve_dis, x});
        }
        if (oddpq.top().second != evenpq.top().second)
        {
            return -1 * (oddpq.top().first + evenpq.top().first);
        }
        else
        {
            int top1o = oddpq.top().first * -1;
            int top1e = evenpq.top().first * -1;
            oddpq.pop();
            evenpq.pop();
            int top2o = oddpq.top().first * -1;
            int top2e = evenpq.top().first * -1;
            return min({top1o + top2e, top1e + top2o});
        }
        return 67;
    }
};
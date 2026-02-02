class Solution
{
public:
    void handleDeletion(int index, int val,
                        set<pair<int, int>> &topK,
                        set<pair<int, int>> &leftOver,
                        int k,
                        long long &sum)
    {
        if (leftOver.find({val, index}) != leftOver.end())
        {
            leftOver.erase({val, index});
        }
        else
        {
            sum -= val;
            topK.erase({val, index});
        }

        if (topK.size() < k && !leftOver.empty())
        {
            auto it = leftOver.begin();
            topK.insert(*it);
            sum += it->first;
            leftOver.erase(it);
        }
    }
    void handleInsertion(int index, int val, set<pair<int, int>> &topK, set<pair<int, int>> &leftOver, int k, long long &sum)
    {
        topK.insert({val, index});
        sum += val;

        if (topK.size() > k)
        {
            auto largest = prev(topK.end());
            sum -= largest->first;
            leftOver.insert(*largest);
            topK.erase(largest);
        }
    }

    long long minimumCost(vector<int> &nums, int k, int dist)
    {
        set<pair<int, int>> topK;
        set<pair<int, int>> leftOver;
        for (int i = 1; i <= dist && i < nums.size(); i++)
        {
            topK.insert({nums[i], i});
            if (topK.size() > k - 2)
            {
                auto temp = *prev(topK.end());
                topK.erase(prev(topK.end()));
                leftOver.insert(temp);
            }
        }
        long long res = LLONG_MAX;
        long long sum = 0;
        for (auto i : topK)
        {
            sum += i.first;
        }
        for (int i = 1; i <= nums.size() - k + 1; i++)
        {
            handleDeletion(i, nums[i], topK, leftOver, k - 2, sum);
            if (i + dist < nums.size())
                handleInsertion(i + dist, nums[i + dist], topK, leftOver, k - 2, sum);
            res = min(res, sum + nums[i]);
        }
        return res + (long long)nums[0];
    }
};
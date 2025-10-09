class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
    int maxn = INT_MIN;
    int minn = INT_MAX;
    for(auto i : nums){
        maxn = max(i,maxn);
        minn = min(i,minn);
    }
    return 1LL * k * (maxn - minn);
    }
};
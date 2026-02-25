class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [](int a, int b)
             {
                 int popA = __builtin_popcount(a);
                 int popB = __builtin_popcount(b);
 if(popA != popB) return popA < popB;
else return a < b; });
        return arr;
    }
};
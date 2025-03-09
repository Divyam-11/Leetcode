class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        int result = 0;
        int l = 0;
        for (int i = 1; i < n + k - 1; i++)
        {
            if (colors[i % n] == colors[(i - 1) % n])
                l = i;
            if (i - l + 1 > k)
                l++;
            if (i - l + 1 == k)
                result++;
        }
        return result;
    }
};
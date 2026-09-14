class Solution
{
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b)
    {
        if (a[2] <= b[0] || b[2] <= a[0])
            return false;

        if (a[3] <= b[1] || b[3] <= a[1])
            return false;

        return true;
    }
};
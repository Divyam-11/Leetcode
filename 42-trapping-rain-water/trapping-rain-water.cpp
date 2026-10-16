class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int temp = height.back();
        vector<int> R(height.size());
        for (int i = height.size() - 1; i >= 0; i--)
        {
            R[i] = max(temp, height[i]);
            temp = max(temp, height[i]);
        }
         temp = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            temp = max(height[i], temp);
            int mini = min(temp, R[i]);
            int contri = mini - height[i];
            if (contri >= 0)
                res += contri;
        }
        return res;
    }
};
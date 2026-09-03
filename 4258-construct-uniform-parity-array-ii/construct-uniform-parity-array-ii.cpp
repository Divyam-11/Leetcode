class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        bool allEven = true;
        bool allOdd = true;
        bool pastOdd = false;
        sort(nums1.begin(),nums1.end());
        // bool pastEven = false;
        for (int i = 0; i < nums1.size(); i++)
        {
            // all even
            if (nums1[i] % 2 == 1)
            {
                allEven = false;
                pastOdd = true;
            }
            else if (nums1[i] % 2 == 0)
            {
                if (!pastOdd)
                    allOdd = false;
            }
        }
        return allEven || allOdd;
    }
};
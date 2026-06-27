class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cand1 = INT_MIN, cand2 = INT_MIN;
        int freq1 = 0, freq2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == cand1)
            {
                freq1++;
            }
            else if (nums[i] == cand2)
                freq2++;
            else if (freq1 == 0)
            {
                cand1 = nums[i];
                freq1 = 1;
            }
            else if (freq2 == 0)
            {
                cand2 = nums[i];
                freq2 = 1;
            }
            else
            {
                freq1--;
                freq2--;
            }
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == cand1)
            {
                c1++;
            }
            if (nums[i] == cand2)
                c2++;
        }
        vector<int> result;
        if(c1 > nums.size() /3) result.push_back(cand1);
        if(c2>nums.size()/3) result.push_back(cand2);
        return result;
    }
};

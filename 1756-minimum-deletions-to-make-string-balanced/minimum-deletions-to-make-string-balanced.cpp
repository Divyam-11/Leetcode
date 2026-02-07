class Solution
{
public:
    int minimumDeletions(string s)
    {
        int curSum = 0;
        vector<int> bCount(s.size());
        vector<int> aCount(s.size());
        int l = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'b')
            {
                if (l == -1)
                    l = i;
                curSum++;
            }
            bCount[i] = curSum;
        }
        curSum = 0;
        int r = -1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'a')
            {
                curSum++;
                if (r == -1)
                    r = i;
            }
            aCount[i] = curSum;
        }
        if (r == -1 || l == -1)
            return 0;
        int adel = 0;
        int bdel = 0;
        cout<<"ayo"<<endl;
        while (l < r && l < s.size() && r >= 0)
        {
            int tempA = aCount[l] - adel;
            int tempB = bCount[r] - bdel;
            if (tempA == 0 && tempB == 0)
            {
                return adel + bdel;
            }
            else if (tempA >= tempB)
            {
                bdel++;
                l++;
                while (l < s.size() and s[l] != 'b')
                {
                    l++;
                }
            }
            else
            {
                adel++;
                r--;
                while (r >= 0 and s[r] != 'a')
                {
                    r--;
                }
            }
        }
        return adel + bdel;
    }
};
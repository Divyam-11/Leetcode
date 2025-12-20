class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int res = 0;
        vector<string> transpose;
        for (int j = 0; j < strs[0].size(); j++)
        {
            string temp;
            for (int i = 0; i < strs.size(); i++)
            {
                temp.push_back(strs[i][j]);
            }
            string sorted_temp = temp;

            sort(sorted_temp.begin(), sorted_temp.end());

            if (sorted_temp != temp)
            {
                res++;
            }
        }
        return res;
    }
}

;
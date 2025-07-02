class Solution
{
public:
    int possibleStringCount(string word)
    {
        int ans = 1;
        int same_count = 0;
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                same_count++;
            }
            else{
                ans+=same_count;
                same_count = 0;
            }
        }
        ans+=same_count;
        return ans;
    }
};
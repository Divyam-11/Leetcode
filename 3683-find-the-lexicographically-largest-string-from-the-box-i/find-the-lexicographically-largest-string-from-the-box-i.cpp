class Solution
{
public:
    string answerString(string word, int numFriends)
    {   
        if(numFriends == 1) return word;
        string ans;
        for (int i = 0; i < word.size(); i++)
        {
            string temp = word.substr(i, word.size() - numFriends+1);
            if (ans.empty())
            {
                ans = temp;
            }
            else
                ans = max(temp, ans);
        }

        return ans;
    }
};
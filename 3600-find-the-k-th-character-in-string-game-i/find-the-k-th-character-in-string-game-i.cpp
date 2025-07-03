class Solution
{
public:
    char kthCharacter(int k)
    {
        string word = "a";
        string ans = word;

        while (ans.size() <= k)
        {
            ans = word;
            for (int i = 0; i < word.size(); i++)
            {
                char temp = word[i];
                temp++;
                if (temp > 'z')
                {
                    temp = 'a';
                }
                ans.push_back(temp);
            }
            word = ans;
        }
        cout<<ans<<endl;
       return ans[k-1];
        }
};
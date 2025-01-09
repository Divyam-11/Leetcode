    class Solution
    {
    public:
        int prefixCount(vector<string> &words, string pref)
        {
            int result = 0;
            for (int i = 0; i < words.size(); i++)
            {
                bool flag = true;
                if(words[i].size() < pref.size()) flag = false;
                for (int j = 0; j < pref.size(); j++)
                {   
                    
                    if (words[i][j] != pref[j])
                    {
                        flag = false;
                    }
                    if(flag == false) break;
                }
                if (flag)
                    result++;
            }
            return result;
        }
    };
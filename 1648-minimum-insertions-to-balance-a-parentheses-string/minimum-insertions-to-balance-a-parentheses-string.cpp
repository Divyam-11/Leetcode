class Solution
{
public:
    int minInsertions(string s)
    {
        int ops = 0;
         int st = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {   
               
                st++;
                
            }
            else
            {
                if (i == s.size() - 1 || s[i + 1] != ')')
                {
                    ops++;
                    if(st)
                    st--;
                    else ops++;
                }
                else if (s[i + 1] == ')')
                {   
                    if(st)
                    st--;   
                    else ops++;
                    i++;
                }
            }
        }
        
        
        return ops + st*2;
    }
};
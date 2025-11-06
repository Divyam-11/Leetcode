class Solution
{
public:
    bool isPossibleToRearrange(string s, string t, int k)
    {   k = s.size() / k;
        unordered_map<string, int> mp;
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            res.push_back(s[i]);
            if (res.size() == k)
            {   
                mp[res]++;
                res.clear();
            }
            
        }
       

        for (int i = 0; i < t.size(); i++)
        {
            res.push_back(t[i]);
            if (res.size() == k)
            {   
                
                if (mp[res] == 0)
                    return false;
                mp[res]--;
                res.clear();
            }
        }
        
        return true;
    }
};
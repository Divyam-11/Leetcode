class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        int discard = 0;
        unordered_map<int, int> mp;
        int l = 0;
        for (int i = 0; i < arrivals.size(); i++)
        {
            
            int window = i - l + 1;
            
            if (window > w)
            { 
                mp[arrivals[l]]--; 
                l++;
                
            }
            int item = arrivals[i];
            if (mp[item] == m)
            { 
                discard++;
                arrivals[i] = 0;
            }
            else
            {
                mp[item]++;
            }
        }
        return discard;
    }
};
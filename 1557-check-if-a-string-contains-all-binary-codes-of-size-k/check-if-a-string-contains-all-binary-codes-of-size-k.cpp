class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {   if(k > s.size()) return false;
        int l = 0;
        int num = 0;
        unordered_set<int> st;
        for (int i = 0; i < k; i++)
        {
            num = num << 1;
            num = num | (s[i] - '0');
        }
        
        st.insert(num);
        for (int i = k; i < s.size(); i++)
        {
            if (s[l] == '1')
            {
                num = num & ~(1 << k-1);
            }
            l++;
            num = num << 1;
            num = num | (s[i] - '0');
            
            st.insert(num);
        }
        return st.size() == (int)pow(2, k);
    }
};
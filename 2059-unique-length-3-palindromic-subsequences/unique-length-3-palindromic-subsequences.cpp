class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int result = 0;
        vector<int> first(26,INT_MAX);
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            first[idx] = min(first[idx], i);
            last[idx] = i;
        }
        for (int i = 0; i < 26; i++)
        {
            if (first[i] < last[i])
            {
                unordered_set<char> st;
                for (int j = first[i] + 1; j < last[i]; j++)
                {
                    st.insert(s[j]);
                }
                result += st.size();
            }
        }
        return result;
    }
};
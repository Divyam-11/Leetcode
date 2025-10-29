class Solution
{
public:
    bool reportSpam(vector<string> &message, vector<string> &bannedWords)
    {
        unordered_set<string> st;
        st.reserve(bannedWords.size() * 2);
        for (auto i : bannedWords)
        {
            st.insert(i);
        }
        int count = 0;
        for (auto i : message)
        {
            if (st.find(i) != st.end())
            {
                count++;
            }
            if(count  > 1) return true;
        }
        return count > 1;
    }
};
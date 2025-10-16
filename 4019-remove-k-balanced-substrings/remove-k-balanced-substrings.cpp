class Solution
{
public:
    string removeSubstring(string s, int k)
    {
        stack<pair<int, int>> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && st.top().first == s[i])
            {
                st.top().second++;
            }
            else
            {
                st.push({s[i], 1});
            }
            if (st.size() >= 2)
            {
                auto top1 = st.top();
                st.pop();
                auto top2 = st.top();
                st.pop();
                if (top1.first == ')' && top1.second == k && top2.first == '(' && top2.second >= k)
                {
                    top2.second -= k;
                    if (top2.second > 0)
                    {
                        st.push(top2);
                    }
                }
                else
                {
                    st.push(top2);
                    st.push(top1);
                }
            }
        }
        string result;
        vector<pair<int,int>> tmp;
        while(!st.empty())
        {
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        for(auto &p: tmp)
        {
            result.append(p.second, p.first);
        }
        return result;
    }
};

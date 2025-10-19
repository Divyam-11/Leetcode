class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        string res = s;
        queue<string> q;
        unordered_set<string> st;
        q.push(s);
        while (!q.empty())
        {
            string temp = q.front();
            q.pop();
            res = min(res, temp);

            string add_temp = temp;
            for (int i = 1; i < add_temp.size(); i+=2)
            {
                if (i % 2 != 0)
                {
                    int s_int = add_temp[i] - '0';
                    s_int += a;
                    s_int %= 10;
                    add_temp[i] = s_int + '0';
                }
            }
            if (st.find(add_temp) == st.end())
            {
                q.push(add_temp);
                st.insert(temp);
            }
            string rot_temp = temp;
            for (int i = 0; i < temp.size(); i++)
            {
                int new_idx = i + b;
                new_idx %= s.size();
                rot_temp[new_idx] = temp[i];
            }
            if (st.find(rot_temp) == st.end())
            {
                q.push(rot_temp);
                st.insert(rot_temp);
            }
        }
        return res;
    }
};
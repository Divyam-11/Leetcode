class Solution
{
public:
    int calculate(string s)
    {
        vector<string> s1;
        string temp;
        if (!isalnum(s[0]) || s[0] != '(')
            temp.push_back('0');
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }

            if (isalnum(s[i]))
                temp.push_back(s[i]);
            else if (!temp.empty())
            {
                s1.push_back(temp);
                temp.clear();
                s1.push_back(string(1, s[i]));
            }

            else if (!s1.empty() && s1.back() == "(" && s[i] != '(')
            {
                s1.push_back("0");
                s1.push_back(string(1, s[i]));
            }
            else
            {
                s1.push_back(string(1, s[i]));
            }
        }
        if (!temp.empty())
            s1.push_back(temp);
        for (auto i : s1)
            cout << i;
        cout << endl;
        stack<char> st;
        vector<string> res;
        for (int i = 0; i < s1.size(); i++)
        {
            if (isalnum(s1[i][0]))
            {
                res.push_back(s1[i]);
            }
            else if (s1[i] == "(")
            {
                st.push(s1[i][0]);
            }
            else if (s1[i] == "+" || s1[i] == "-")
            {
                while (!st.empty() && (st.top() == '+' || st.top() == '-'))
                {
                    res.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s1[i][0]);
            }
            else if (s1[i] == ")")
            {
                while (!st.empty() && st.top() != '(')
                {
                    res.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();
            }
        }
        while (!st.empty())
        {
            res.push_back(string(1, st.top()));
            st.pop();
        }
        for (auto i : res)
            cout << i;
        stack<long long> st2;
        for (int i = 0; i < res.size(); i++)
        {
            if (isalnum(res[i][0]))
                st2.push(stoll(res[i]));
            else if (res[i] == "+")
            {
                long long temp1 = st2.top();
                st2.pop();
                long long temp2 = st2.top();
                st2.pop();
                st2.push(temp1 + temp2);
            }
            else if (res[i] == "-")
            {
                long long temp1 = st2.top();
                st2.pop();
                long long temp2 = st2.top();
                st2.pop();
                st2.push(temp2 - temp1);
            }
        }
        return st2.top();
    }
};
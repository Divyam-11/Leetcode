class Solution
{
public:
    void solve(int open, int close, string &temp, set<string> &st)
    {
        if (open == 0 && close == 0)
        {
            st.insert(temp);
            return;
        }
        if(open > 0){
        open--;
        temp.push_back('(');
        solve(open, close, temp, st);
        open++;
        temp.pop_back();
        }
        if (close > open)
        {
            close--;
            temp.push_back(')');
            solve(open, close, temp, st);
            close++;
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string temp;
        set<string> st;
        solve(n, n, temp, st);
        return vector<string>(st.begin(), st.end());
    }
};
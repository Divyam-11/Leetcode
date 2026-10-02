class Solution
{
public:
    void solve(int &open, int &close, string &temp, vector<string> &st)
    {
        if (open == 0 && close == 0)
        {
            st.push_back(temp);
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
        vector<string> st;
        int n2 = n;
        solve(n,n2 , temp, st);
        return st;
    }
};
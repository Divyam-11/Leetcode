class Solution
{
    string result;
    vector<char> v = {'a', 'b', 'c'};
    void func(string &ans, int &n, int &k, int &result_count)
    {
        if (!result.empty())
            return;
        if (ans.size() == n)
        {
            result_count++;
            if (result_count == k)
            {
                result = ans;
                return;
            }
            return;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (ans.empty() || ans.back() != v[i])
            {
                ans.push_back(v[i]);
                func(ans, n, k, result_count);
                ans.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k)
    {
        int result_count = 0;
        string ans = "";
        func(ans, n, k, result_count);
        return result;
    }
};
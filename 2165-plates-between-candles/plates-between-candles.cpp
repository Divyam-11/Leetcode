class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> nextRight(n);
        vector<int> lastLeft(n);
        vector<int> prefix(n);

        int lL = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
            {
                lL = i;
            }
            lastLeft[i] = lL;
            prefix[i] = i == 0 ? 0 : prefix[i - 1];
            prefix[i] += (s[i] == '*');
        }
        int nR = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '|')
            {
                nR = i;
            }
            nextRight[i] = nR;
        }
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int l = nextRight[left];
            int r = lastLeft[right];
            if(l == -1 || r == -1) continue;
            if(l >= r) continue;
            result[i] = prefix[r] - prefix[l];
        }
        return result;
    }
};
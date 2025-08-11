class Solution
{
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> result;
        vector<int> binary_n;
        while (n)
        {
            binary_n.push_back((n % 2) ? 1 : 0);
            n /= 2;
        }
        vector<int> powers;
        for (int i = 0; i < binary_n.size(); i++)
        {   
            if(binary_n[i] == 1)
            powers.push_back((int)pow(2, i));
        }
        for (int i = 0; i < queries.size(); i++)
        {
            long long product = 1;
            
            for (int j = queries[i][0]; j <=queries[i][1]; j++)
            {   
                product *= powers[j] % mod; 
                product = product % mod;
                
            }
            result.push_back((int)product);
        }
        return result;
    }
};
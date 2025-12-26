class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int time = INT_MIN;
        int res = customers.size();
        int sum = 0;
        vector<int> prefix(customers.size());
        for (int i = customers.size()-1; i >= 0; i--)
        {

            if (customers[i] == 'Y')
            {
                sum++;
            }
            prefix[i] = sum;
        }
        sum = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if (prefix[i] + sum < res)
            {
                res = prefix[i] + sum;
                time = i;
            }

            if (customers[i] == 'N')
                sum++;
        }
        if(sum < res){
            time = customers.size();

        }
        return time;
    }
};
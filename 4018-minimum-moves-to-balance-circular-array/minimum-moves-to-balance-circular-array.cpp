class Solution
{
public:
    long long minMoves(vector<int> &balance)
    {
        int neg_index =-1;
        long long sum = 0;
        for (int i = 0; i < balance.size(); i++)
        {
            if (balance[i] < 0)
            {
                neg_index = i;
            }
            else
                sum += balance[i];
        }
        if(neg_index == -1) return 0;
        if (abs(balance[neg_index]) > sum)
            return -1;
        int i = 1;
        long long cost = 0;
        long long total_moved = abs(balance[neg_index]);
        while (total_moved > 0)
        {
            int left = neg_index - i + balance.size();
            int right = neg_index + i + balance.size();
            left %= balance.size();
            right %= balance.size();
            long long l_take = min(total_moved, (long long)balance[left]);
            total_moved -= l_take;
            cost += l_take * i;
            long long r_take = min(total_moved, (long long)balance[right]);
            total_moved -= r_take;
            cost += r_take * i;
            i++;
        }
        return cost;
    }
};
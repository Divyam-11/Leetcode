class Solution
{
public:
    pair<int, int> returnSmallest(vector<int> &unit)
    {
        if (unit.size() == 1)
            return {unit[0], unit[0]};
        int smallest = INT_MAX, second_smallest = INT_MAX;
        for (int i = 0; i < unit.size(); i++)
        {
            if (unit[i] < smallest)
            {
                second_smallest = smallest;
                smallest = unit[i];
                
            }
            else if (unit[i] <= second_smallest)
            {
                second_smallest = unit[i];
            }
        }
        return {smallest, second_smallest};
        
        
    }
    long long maxRatings(vector<vector<int>> &units)
    {
        int m = units.size();
        int n = units[0].size();

        long long sum = 0;
        int smallest = INT_MAX;
        int smallest_second_smallest = INT_MAX;
        for (int i = 0; i < units.size(); i++)
        {
            auto temp = returnSmallest(units[i]);
            sum += temp.second;
            smallest = min(smallest, temp.first);
            smallest_second_smallest = min(smallest_second_smallest, temp.second);
        }
        sum -= smallest_second_smallest;
        sum += smallest;
        return sum;
    }
};
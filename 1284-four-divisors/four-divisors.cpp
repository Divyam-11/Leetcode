class Solution
{
public:
    int getDiv(int num)
    {
        int count = 0;
        int sum = 0;
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                count++;
                sum += i;
            }
            if(count > 4) return 0;
        }
        
        if (count != 4)
            return 0;
        return sum;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum+=getDiv(nums[i]);
        }
        return sum;
    }
};
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> modulo_1;
        priority_queue<int, vector<int>, greater<int>> modulo_2;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (nums[i] % 3 == 1)
            {
                modulo_1.push(nums[i]);
            }
            if (nums[i] % 3 == 2)
            {
                modulo_2.push(nums[i]);
            }
        }
        int rem = sum % 3;
        if (rem == 1)
        {
            int two_sum = 0;
            if (modulo_2.size() >= 2)
            {
                two_sum = sum;
                two_sum -= modulo_2.top();
                modulo_2.pop();
                two_sum -= modulo_2.top();
                modulo_2.pop();
            }
            int one_sum = 0;
            if (modulo_1.size() >= 1)
            {
                one_sum = sum;
                one_sum -= modulo_1.top();
                modulo_1.pop();
            }
            return max(one_sum, two_sum);
        }
        if (rem == 2)
        {
            int two_sum = 0;
            if (modulo_1.size() >= 2)
            {
                two_sum = sum;
                two_sum -= modulo_1.top();
                modulo_1.pop();
                two_sum -= modulo_1.top();
                modulo_1.pop();
            }
            int one_sum = 0;
            if (modulo_2.size() >= 1)
            {
                one_sum = sum;

                one_sum -= modulo_2.top();
                modulo_2.pop();
            }
            return max(one_sum, two_sum);
        }
        return sum;
    }
};
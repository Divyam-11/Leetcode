class Solution
{
public:
    bool isSymmetric(int num)
    {

        string str = to_string(num);
        if (str.size() % 2 != 0)
            return false;
        int i = 0;
        int j = str.size() - 1;
        int left_sum = 0;
        int right_sum = 0;
        while (i < j)
        {
            left_sum += str[i] - '0';
            right_sum += str[j] - '0';
            i++;
            j--;
        }
        return left_sum == right_sum;
    }
    int countSymmetricIntegers(int low, int high)
    {
        int result = 0;
        for (int i = low; i <= high; i++)
        {
            if (isSymmetric(i))
            {
                result++;
            }
        }
        return result;
    }
};
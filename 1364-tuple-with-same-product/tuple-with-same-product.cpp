class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int result = 0;
        unordered_map<int, int> product;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                product[nums[i] * nums[j]]++;
            }
        }
        for (auto i : product)
        {
            result += (i.second * (i.second - 1)) / 2;
        }
        return result * 8;
    }
};
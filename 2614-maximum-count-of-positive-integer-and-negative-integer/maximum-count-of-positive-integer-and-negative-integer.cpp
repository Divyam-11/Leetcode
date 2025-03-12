class Solution
{
public:
  int maximumCount(vector<int> &nums)
  {
    int negative_count = 0;
    int positive_count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
        positive_count++;
      else if (nums[i] < 0)
        negative_count++;
    }
    return max(positive_count, negative_count);
  }
};
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_set<int> arr_set(arr.begin(), arr.end());

        int result = 0;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                int prev = arr[i];
                int curr = arr[j];
                int next = prev + curr;
                int length = 2;
                while (arr_set.find(next) != arr_set.end())
                {
                    length++;
                    prev = curr;
                    curr = next;
                    next = prev + curr;
                    result = max(result, length);
                }
            }
        }
        return result;
    }
};
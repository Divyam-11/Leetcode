class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        if(arr.size() == 0) return {};
        vector<int> arr2 = arr;
        sort(arr2.begin(), arr2.end());
        int rank = 1;
        unordered_map<int, int> mp;
        mp[arr2[0]] = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr2[i] == arr2[i - 1])
            {
                mp[arr2[i]] = rank;
            }
            else
            {
                rank++;
                mp[arr2[i]] = rank;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr2[i] = mp[arr[i]];
        }
        return arr2;
    }
};
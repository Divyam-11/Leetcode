class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> answer;
        vector<int> first_index(26, -1);
        vector<int> last_index(26);
        for (int i = 0; i < s.size(); i++)
        {
            if (first_index[s[i] - 'a'] == -1)
                first_index[s[i] - 'a'] = i;
            last_index[s[i] - 'a'] = i;
        }
        int last_subarray_index = 0;
        int l=0, r = 0;
        while (l < s.size() && r < s.size())
        {

            r = max(r, last_index[s[l] - 'a']);
            
            if (l == r)
            {
                answer.push_back(r - last_subarray_index + 1);
                last_subarray_index = r + 1;
            }
            l++;
        }
        return answer;
    }
};
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> answer;
        vector<int> freq(26, 0);
        for (int i = 0; i < words2.size(); i++)
        {
            vector<int> temp(26, 0);
            for (int j = 0; j < words2[i].size(); j++)
            {
                temp[words2[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; j++)
            {
                freq[j] = max(freq[j], temp[j]);
            }
        }
        for (int i = 0; i < words1.size(); i++)
        {
            vector<int> temp(26, 0);
            for (int j = 0; j < words1[i].size(); j++)
            {
                temp[words1[i][j] - 'a']++;
            }
            bool flag = true;
            for (int j = 0; j < 26; j++)
            {
                if (temp[j] < freq[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                answer.push_back(words1[i]);
        }
        return answer;
    }
};
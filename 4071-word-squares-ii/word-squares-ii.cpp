class Solution
{
public:
    bool isValid(string top, string left, string right, string bottom)
    {
        if (top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3])
            return true;
        return false;
    }
    vector<vector<string>> wordSquares(vector<string> &words)
    {
        vector<vector<string>> result;
        sort(words.begin(),words.end());
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (j == i)
                    continue;
                for (int k = 0; k < words.size(); k++)
                {
                    if (k == j || k == i)
                        continue;
                    for (int l = 0; l < words.size(); l++)
                    {
                        if (l == i || l == j || l == k)
                            continue;
                        string top = words[i];
                        string left = words[j];
                        string right = words[k];
                        string bottom = words[l];
                        if (isValid(top, left, right, bottom))
                        {
                            result.push_back({top, left, right, bottom});
                        }
                    }
                }
            }
        }
        
               return result;
    }
};
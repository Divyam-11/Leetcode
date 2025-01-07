class Solution {
public:
vector<string> stringMatching(vector<string> &words)
{
    unordered_set<string> uniqueResults; 
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (j == i)
                continue;
            if (words[j].find(words[i]) != string::npos)
            {
                uniqueResults.insert(words[i]);
                break; 
            }
        }
    }

    
    return vector<string>(uniqueResults.begin(), uniqueResults.end());
}
};
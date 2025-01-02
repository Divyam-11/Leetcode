class Solution
{
public:
bool isValid(const string &word)
{
    string vowels = "aeiou";
    return vowels.find(word.front()) != string::npos && vowels.find(word.back()) != string::npos;
}
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)

    {
        vector<int> prefix;
        int sum = 0;
        for (auto i : words)
        {
            if (isValid(i))
            {
                sum++;
            }
            prefix.push_back(sum);
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int temp = prefix[r] - prefix[l];
            if (isValid(words[l]))
                temp++;

            result.push_back(temp);
        }
        return result;
    }
};
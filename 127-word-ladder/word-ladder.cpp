class Solution
{
public:
    int hamDistance(string &word1, string &word2)
    {
        int diff = 0;
        for (int i = 0; i < word1.size(); i++)
        {
            if (word1[i] != word2[i])
                diff++;
        }
        return diff;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        bool flag = false;
        for (auto &word : wordList)
        {
            if (word == endWord)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
        set<string> st;
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        st.insert(beginWord);
        while (!q.empty())
        {
            int cost = q.front().first;
            string word = q.front().second;
            q.pop();
            for (int i = 0; i < wordList.size(); i++)
            {
                if (hamDistance(word, wordList[i]) == 1)
                {
                    if (wordList[i] == endWord)
                        return cost + 1;
                    if (st.find(wordList[i]) == st.end())
                    {
                        st.insert(wordList[i]);
                        q.push({cost + 1, wordList[i]});
                    }
                }
            }
        }
        return 0;
    }
};
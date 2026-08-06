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
        set<string> wl(wordList.begin(), wordList.end());
        set<string> st;
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        st.insert(beginWord);
        while (!q.empty())
        {
            int cost = q.front().first;
            string word = q.front().second;
            q.pop();
            for (int i = 0; i < word.size(); i++)
            {
                char temp = word[i];
                for (int j = 0; j < 26; j++)
                {
                    word[i] = j + 'a';
                    if (wl.find(word) != wl.end() && st.find(word) == st.end())
                    {
                        if (word == endWord)
                            return cost + 1;
                        q.push({cost + 1, word});
                        st.insert(word);
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};
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

        queue<pair<int, string>> q;
        q.push({1, beginWord});
        wl.erase(beginWord);
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
                    if (wl.find(word) != wl.end())
                    {
                        if (word == endWord)
                            return cost + 1;
                        q.push({cost + 1, word});
                        wl.erase(word);
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
    void dfs(string word, int cost, int &LL, string &beginWord, string &endWord, set<string> &wl, set<string> &st, vector<string> &key, vector<vector<string>> &result)
    {
        if (cost >= LL)
            return;
        st.insert(word);
        for (int i = 0; i < word.size(); i++)
        {
            char temp = word[i];
            for (int j = 0; j < 26; j++)
            {
                word[i] = j + 'a';
                if (wl.find(word) != wl.end())
                {
                    if (word == endWord)
                    {
                        key.push_back(word);
                        result.push_back(key);
                        key.pop_back();
                        return;
                    }
                    key.push_back(word);
                    dfs(word, cost + 1, LL, beginWord, endWord, wl, st, key, result);
                    key.pop_back();
                }
            }
            word[i] = temp;
        }
        st.erase(word);
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int LL = ladderLength(beginWord, endWord, wordList);
        set<string> wl(wordList.begin(), wordList.end());
        set<string> st;
        vector<string> key;
        vector<vector<string>> result;
        dfs(beginWord, 0, LL, beginWord, endWord, wl, st, key, result);
        return result;
    }
};

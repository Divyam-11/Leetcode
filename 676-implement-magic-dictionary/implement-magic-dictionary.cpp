struct Node
{
    Node *arr[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (arr[ch - 'a'] != nullptr);
    }
    void set(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool getEnd()
    {
        return flag;
    }
};
class MagicDictionary
{
public:
    Node *root;
    MagicDictionary()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->set(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    void buildDict(vector<string> dictionary)
    {
        for (int i = 0; i < dictionary.size(); i++)
        {
            insert(dictionary[i]);
        }
    }
    bool dfs(int idx, string &word, bool charge, Node *node)
    {
        if (idx == word.size() && charge)
        {
            return node->getEnd();
        }
        // bool res = false;
        for (int i = 0; i < 26; i++)
        {
            if (node->arr[i] != nullptr)
            {
                if (i == word[idx] - 'a')
                {
                    if (dfs(idx + 1, word, charge, node->get(i + 'a')))
                        return true;
                }
                if (i != word[idx] - 'a' && charge == false)
                {
                    if (dfs(idx + 1, word, true, node->get(i + 'a')))
                        return true;
                }
            }
        }
        return false;
    }

    bool search(string searchWord)
    {
        return dfs(0, searchWord, false, root);
    }
};
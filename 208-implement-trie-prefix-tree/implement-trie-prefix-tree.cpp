struct Node
{
    Node *arr[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (arr[ch - 'a'] != nullptr);
    }
    void setKey(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }
    Node *move(char ch)
    {
        return arr[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
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
                node->setKey(word[i], new Node());
            }
            node = node->move(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->move(word[i]);
        }
        return node->flag;
    }

    bool startsWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->move(word[i]);
        }
        return true;
    }
};
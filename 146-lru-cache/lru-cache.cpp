struct DLL
{
    int key;
    int val;
    DLL *next;
    DLL *back;

    DLL() : key(0), val(0), next(nullptr), back(nullptr) {}

    DLL(int x, int y) : key(x), val(y), next(nullptr), back(nullptr) {}
};

class LRUCache
{
public:
    int cap;
    int count;
    unordered_map<int, DLL *> mp;
    DLL *top;
    DLL *end;

    LRUCache(int capacity)
    {
        count = 0;
        cap = capacity;
        top = new DLL(-67, -67);
        end = top;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            DLL *node = mp[key];

            if (node != end)
            {
                DLL *back = node->back;
                DLL *next = node->next;

                back->next = next;

                if (next)
                    next->back = back;

                end->next = node;
                node->back = end;
                node->next = nullptr;
                end = node;
            }

            return node->val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            DLL *node = mp[key];
            node->val = value;

            if (node != end)
            {
                DLL *back = node->back;
                DLL *next = node->next;

                back->next = next;

                if (next)
                    next->back = back;

                end->next = node;
                node->back = end;
                node->next = nullptr;
                end = node;
            }

            return;
        }

        if (count < cap)
        {
            DLL *temp = new DLL(key, value);

            mp[key] = temp;

            end->next = temp;
            temp->back = end;
            end = temp;

            count++;
        }
        else
        {
            DLL *temp = top->next;

            mp.erase(temp->key);

            if (temp == end)
            {
                temp->key = key;
                temp->val = value;
                mp[key] = temp;
                return;
            }

            top->next = temp->next;
            temp->next->back = top;

            end->next = temp;
            temp->back = end;
            temp->next = nullptr;
            end = temp;

            temp->key = key;
            temp->val = value;

            mp[key] = temp;
        }
    }
};
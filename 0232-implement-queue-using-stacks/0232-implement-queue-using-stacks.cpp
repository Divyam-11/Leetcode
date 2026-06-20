class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s1.empty())
            return 0;
        while (s1.size() != 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s1.top();
        s1.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }

    int peek()
    {
        if (s1.empty())
            return 0;
        while (s1.size() != 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s1.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }

    bool empty()
    {
        return s1.empty();
    }
};

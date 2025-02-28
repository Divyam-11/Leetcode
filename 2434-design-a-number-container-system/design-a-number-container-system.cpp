class NumberContainers
{
public:
    unordered_map<int, int> container;        // {index,number}
    unordered_map<int, set<int>> container_2; //{number,index}

    NumberContainers()

    {
    }

    void change(int index, int number)
    {
        if (container.find(index) == container.end())
        {
            container[index] = number;
            container_2[number].insert(index);
            return;
        }
        else
        {
            int temp = container[index];

            container_2[temp].erase(index);
            if (container_2[temp].empty())
            {
                container_2.erase(temp);
            }
            container[index] = number;
            container_2[number].insert(index);
        }
    }

    int find(int number)
    {
        if (container_2.find(number) != container_2.end())
            return *(container_2[number].begin());
        return -1;
    }
};
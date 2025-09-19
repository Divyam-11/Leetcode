class Spreadsheet
{
public:
    unordered_map<char, unordered_map<int, int>> mp;
    Spreadsheet(int rows)
    {
    }

    void setCell(string cell, int value)
    {
        char alpha = cell[0];
        string num = cell.substr(1);
        mp[alpha][stoi(num)] = value;

    }

    void resetCell(string cell)
    {
        char alpha = cell[0];
        string num = cell.substr(1);
        mp[alpha][stoi(num)] = 0;
    }

    int getValue(string formula)
    {
        int i = 1;
        string op1 = "";
        string op2 = "";
        while (formula[i] != '+')
        {
            op1.push_back(formula[i]);
            i++;
        }
        i++;
        while (i < formula.size())
        {
            op2.push_back(formula[i]);
            i++;
        }

        int val1 = 0;
        int val2 = 0;
        if (isalpha(op1[0]))
        {

            val1 = mp[op1[0]][stoi(op1.substr(1))];
        }
        else
        {
            val1 = stoi(op1);
        }
        if (isalpha(op2[0]))
        {
            val2 = mp[op2[0]][stoi(op2.substr(1))];
        }
        else
        {
            val2 = stoi(op2);
        }

        return val1 + val2;
    }
};

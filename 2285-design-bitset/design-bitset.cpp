class Bitset
{
    string bits;
    string bitsInv;
    int count0 = 0;
    int count1 = 0;

public:
    Bitset(int size)
    {
        bits += string(size,'0');
        bitsInv += string(size,'1');
        count0 = size;
        count1=0;
    }

    void fix(int idx)
    {
        if (bits[idx] != '1')
        {
            bits[idx] = '1';
            bitsInv[idx] = '0';
            count0--;
            count1++;
        }
    }

    void unfix(int idx)
    {
        if (bits[idx] != '0')
        {
            bits[idx] = '0';
            bitsInv[idx] = '1';
            count0++;
            count1--;
        }
    }

    void flip()
    {
        swap(bits, bitsInv);
        swap(count0,count1);
    }

    bool all()
    {
        return count0==0;
    }

    bool one()
    {
        return count1>=1;
    }

    int count()
    {
        return count1;
    }

    string toString()
    {
        return bits;
    }
};
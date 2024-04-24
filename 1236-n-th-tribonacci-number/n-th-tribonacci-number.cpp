class Solution{ 
    public:
    int tribonacci(int n) {
        if(n < 2)
            return n;
        int a1 = 0, a2 = 1, a3 = 1, t;
        while(n > 2) {
            t = a1 + a2 + a3;
            a1 = a2;
            a2 = a3;
            a3 = t;
            n--;
        }
        return a3;
    }
};
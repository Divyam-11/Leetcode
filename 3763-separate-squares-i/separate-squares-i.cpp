class Solution
{
public:
    double check(double mid, vector<vector<int>> &squares)
    {
        double area = 0;
        for (int i = 0; i < squares.size(); i++)
        {
            double x = squares[i][0];
            double y = squares[i][1];
            double length = squares[i][2];
            if (y < mid)
            {
                double upperCap = min(y + length, mid);
                area += (upperCap - y) * length;
            }
        }

        return area;
    }
    double separateSquares(vector<vector<int>> &squares)
    {
        double area = 0;
        double maxY = 0;
        for (int i = 0; i < squares.size(); i++)
        {
            area += (double)squares[i][2] * (double)squares[i][2];
            maxY = max(maxY, double(squares[i][1] + squares[i][1]));
        }

        double low = 0;
        double high = maxY;
        double res = 0;
        double eps = 1e-8;
        int epochs = 60;
        while (high - low > eps && epochs--) 
        {
            double mid = low + (high - low) / 2;
            double temp = check(mid, squares);

            if (abs(res - mid) < eps)
                return res;
            if (temp >= area / 2)
            {

                high = mid;
            }
            else
            {
                res = mid;
                low = mid;
            }
        }
        return res;
    }
};
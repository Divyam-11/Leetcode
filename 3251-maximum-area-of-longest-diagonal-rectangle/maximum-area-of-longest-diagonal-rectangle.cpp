class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        double max_diagonal = 0;
        int max_area = 0;
        for (int i = 0; i < dimensions.size(); i++)
        {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            double diagonal = sqrt(l * l + w * w);
            cout<<diagonal<<endl;
            if (diagonal > max_diagonal)
            {
                max_diagonal = diagonal;
                max_area = l * w;
            }
            else if (diagonal == max_diagonal)
            {
                max_area = max(max_area, l * w);
            }
        }
        return max_area;
    }
};
class Solution
{
public:
    template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        vector<vector<int>> traversal;
        for (int i = 0; i < mat.size(); i++)
        {
            int x = i;
            int y = 0;
            vector<int> temp;
            while (x >= 0 && y < n)
            {   
                temp.push_back(mat[x][y]);
                x--;
                y++;
            }
            if (traversal.size() % 2 != 0)
            {
                reverse(temp.begin(), temp.end());
            }
           
            traversal.push_back(temp);
            
        }
        for (int i = 1; i < n; i++)
        {
            int x = m - 1;
            int y = i;
            vector<int> temp;
            
            while (x >= 0 && y < n)
            {  
                temp.push_back(mat[x][y]);
                
                x--;
                y++;
            }
            if (traversal.size() % 2 != 0)
            {
                reverse(temp.begin(), temp.end());
            }
            
            traversal.push_back(temp);
            
        }
        for (int i = 0; i < traversal.size(); i++)
        {   printVector(traversal[i]);
            for (int j = 0; j < traversal[i].size(); j++)
            {   cout<<traversal[i][j]<<endl;
                result.push_back(traversal[i][j]);
            }
        }
        return result;
    }
};
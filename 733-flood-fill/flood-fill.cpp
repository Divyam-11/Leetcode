class Solution
{
public:
    vector<int> rows = {0, -1, 0, 1};
    vector<int> cols = {-1, 0, 1, 0};
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        int src_color = image[sr][sc];
        q.push({sr, sc});
        image[sr][sc] = color;
        if(src_color == color) return image;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = x + rows[i];
                int newCol = y + cols[i];
                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                    continue;
                if (image[newRow][newCol] == src_color)
                {
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};
class Solution {
    private:
    void dfs(vector<vector<int>> & image, int sr,int sc ,int color,int og_pixel){
        if(sr < 0 || sr>=image.size() || sc < 0 || sr >= image[0].size()) return ;
        if(image[sr][sc] == color) return;
        if(image[sr][sc] != og_pixel ) return;
        image[sr][sc] = color;
        dfs(image,sr+1,sc,color,og_pixel);
        dfs(image,sr,sc+1,color,og_pixel);
        dfs(image,sr-1,sc,color,og_pixel);
        dfs(image,sr,sc-1,color,og_pixel);
        return;

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og_pixel = image[sr][sc];
        dfs(image,sr,sc,color,og_pixel);
        return image;
    }
};
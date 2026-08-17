class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& img,int sr,int sc,vector<vector<bool>>& visited,int og,int color)
    {
        if(sr < 0 || sr >= m || sc < 0 || sc >= n)
            return;
        if(visited[sr][sc])
            return;
        if(img[sr][sc] != og)
            return;
        visited[sr][sc] = true;
        img[sr][sc] = color;
        dfs(img, sr + 1, sc, visited, og, color);
        dfs(img, sr - 1, sc, visited, og, color);
        dfs(img, sr, sc + 1, visited, og, color);
        dfs(img, sr, sc - 1, visited, og, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int color)
    {
        int og = image[sr][sc];
        if(og == color)
            return image;
         m = image.size();
         n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(image, sr, sc, visited, og, color);
        return image;
    }
};
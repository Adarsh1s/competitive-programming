class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int n, int m,int temp){

        if(sr<0 || sc<0) return;
        if(sr>=n || sc>=m) return;
        if(image[sr][sc] != temp || image[sr][sc] == color) return;

        image[sr][sc] = color;
        dfs(image,sr-1,sc,color,n,m,temp);
        dfs(image,sr+1,sc,color,n,m,temp);
        dfs(image,sr,sc+1,color,n,m,temp);
        dfs(image,sr,sc-1,color,n,m,temp);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int temp = image[sr][sc];
        dfs(image,sr,sc,color,n,m,temp);
        return image;
    }
};
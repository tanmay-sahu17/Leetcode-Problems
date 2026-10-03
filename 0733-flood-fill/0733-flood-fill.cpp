class Solution {
public:
    void dfs(vector<vector<int>>&image,int originalcolor,int sr,int sc,int color,int m,int n){
        if(sr>=m||sr<0||sc<0||sc>=n){
            return;
        }
        if(originalcolor!=image[sr][sc])return;
        image[sr][sc]=color;

        dfs(image,originalcolor,sr+1,sc,color,m,n);
        dfs(image,originalcolor,sr,sc+1,color,m,n);
        dfs(image,originalcolor,sr-1,sc,color,m,n);
        dfs(image,originalcolor,sr,sc-1,color,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor=image[sr][sc];
        if(originalcolor==color){
            return image;
        }
        int m=image.size();
        int n=image[0].size();
        dfs(image,originalcolor,sr,sc,color,m,n);

        return image;
    }
};
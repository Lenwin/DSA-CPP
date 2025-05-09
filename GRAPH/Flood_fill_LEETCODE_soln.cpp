class Solution {
    private:
        void dfs(vector<vector<int>>&ans,int inicolor,int delrow[],int delcol[],int color,vector<vector<int>>&image,int row,int col){
            int n = image.size();
            int m = image[0].size();
            //Changing the color of the pixel into the given color
            ans[row][col]=color;
            //Doing DFS for 4 adjacent pixels up,down,left,right
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                //Checking if the new row is valid and if the pixel have same colour as initial color and making sure that it is not flood filled
                if(nrow>=0&&nrow<n&&ncol<m&&ncol>=0&&image[nrow][ncol]==inicolor&&ans[nrow][ncol]!=color){
                    dfs(ans,inicolor,delrow,delcol,color,image,nrow,ncol);
                }
            }
        }
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int inicolor = image[sr][sc];
            vector<vector<int>>ans = image;
            //To call adjacent pixels
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            //Calling DFS
            dfs(ans,inicolor,delrow,delcol,color,image,sr,sc);
            return ans;
    
            
        }
    };
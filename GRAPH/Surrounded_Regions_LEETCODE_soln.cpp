class Solution {
private:
    void dfs(int row,int col,vector<int>&delrow,vector<int>&delcol,vector<vector<char>>&board,vector<vector<int>>&visited){
        int n = board.size();
        int m = board[0].size();
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&board[nrow][ncol]=='O'&&visited[nrow][ncol]==0){
                dfs(nrow,ncol,delrow,delcol,board,visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m = board[0].size();
        //Creating a matrix visited to keep track of visited elements
        vector<vector<int>>visited(n,vector<int>(m,0));
        //DFS traversal of the board.
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        //If any of the cells O are not surrounded by X then we should be able to reach them using DFS traversal from any of the border cells.
        //We will start DFS traversal from the border cells if they are O.
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'&&visited[0][i]==0){
                dfs(0,i,delrow,delcol,board,visited);
            }
            if(board[n-1][i]=='O'&&visited[n-1][i]==0){
                dfs(n-1,i,delrow,delcol,board,visited);
            }
        }
        for(int j=0;j<n;j++){
            if(board[j][0]=='O'&&visited[j][0]==0){
                dfs(j,0,delrow,delcol,board,visited);
            }
            if(board[j][m-1]=='O'&&visited[j][m-1]==0){
                dfs(j,m-1,delrow,delcol,board,visited);
            }
        }
        //Finally if any of the cell with O is not visited that means it is surrounded by X so we will change it to X
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&visited[i][j]==0){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
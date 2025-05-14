class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Matrix to keep track of visited elements
        vector<vector<int>>visited(n,vector<int>(m,0));
        //Queue for BFS traversal which store index of the node
        queue<pair<int,int>>q;
        //For a land(1) to be not surrounded by sea(0) we should be able to reach the land cell using BFS from the border cells.
        //For that we push all the border cells which have 1 to the queue to start BFS from it
        for(int i=0;i<n;i++){
            if(grid[i][0]==1&&visited[i][0]==0){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(grid[i][m-1]==1&&visited[i][m-1]==0){
                q.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1&&visited[0][j]==0){
                q.push({0,j});
                visited[0][j]=1;
            }
            if(grid[n-1][j]==1&&visited[n-1][j]==0){
                q.push({n-1,j});
                visited[n-1][j]=1;
            }
        }
        //BFS traversal of the matrix
        //For easily traversing the cell above,below,right and left.
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                //If the cell has value 1 and is not visited we push them into the queue and mark them visited
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1&&visited[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }

            }
        }
        //If the value of cell is 1 and it is not visited using the bfs from border cells we can say that we can walk off to the boundary in Land.
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&visited[i][j]==0){
                    count++;
                }
            }
        }
        return count;
        
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        //Initializing two matrices visited and distance
        //Visited keeps tracks of visited elements
        //Distance stores the distance to the nearest 0
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        //Queue contains two pairs the inner pair stores the index of the cell and the second value of outer pair stores the number of steps it took took to reach the current cell
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    //Pushing all cells with values zero into the queue and making them visited
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        //BFS traversal of the matrix 
        //To traverse in 4 directions easily
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[r][c] = steps;
            for(int i=0;i<4;i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                //If the node is unvisited we push into the queue and increase the step by 1
                if(nrow<m&&nrow>=0&&ncol>=0&&ncol<n&&vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
            
        }
        return dist;
        
    }
};
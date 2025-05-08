class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            //Creating a queue which stores the index of the matrix and time 
            queue<pair<pair<int,int>,int>>q;
            //creating a matrix to keep track of visited elements
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            int cntfresh=0;
            //Traversing through the matrix
            //Pushing Elements into queue if it is rotten for BFS traversal
            //We will also count the number of fresh orange
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==2){
                        //Index of matrix is the first pair and its time is the second element
                        q.push({{i,j},0});
                        vis[i][j]=2;
                    }
                    else{
                        vis[i][j] = 0;
                    }
                    if(grid[i][j]==1)cntfresh++;
                }
            }
            int tm =0;
            //BFS traversal
            vector<int> drow = {-1,0,1,0};
            vector<int>dcol  = {0,1,0,-1};
            int cnt = 0;
            while(!q.empty()){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                //Keeping track of time
                tm = max(tm,t);
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow = r+drow[i];
                    int ncol = c+dcol[i];
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]!=2&&grid[nrow][ncol]==1){
                        vis[nrow][ncol]=2;
                        //Pushing index and the time required for them to be rotten
                        q.push({{nrow,ncol},t+1});
                        //counting number of fresh oranges which are rotten now
                        cnt++;
                    }
                }
            }
           if(cnt!=cntfresh){
            return -1;
           }
            return tm;
    
            
        }
    };
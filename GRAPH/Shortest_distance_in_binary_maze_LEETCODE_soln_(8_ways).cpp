class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int,int>source = {0,0};
        pair<int,int>destination = {n-1,m-1};
        if(source==destination&&grid[source.first][source.second]==0){
            return 1;
        }
        if(grid[0][0]==1||grid[n-1][m-1]==1){
            return -1;
        }
        queue<pair<int,pair<int,int>>>q;
        //Distance vector initialized as infinity
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        //Making distance to source node as zero and pushing it into queue
        dist[0][0]=1;
        q.push({1,{0,0}});
        //Vectors for traversal in 4 directions and BFS
        vector<int>delrow = {-1,-1,0,1,1,1,0,-1};
        vector<int>delcol = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int distance  = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int newrow = row+delrow[i];
                int newcol = col+delcol[i];
                if(newrow<n&&newrow>=0&&newcol<m&&newcol>=0&&grid[newrow][newcol]==0&&
                distance+1<dist[newrow][newcol]){
                    dist[newrow][newcol]=distance+1;
                    //If new row and new column is equal to destination address return distance
                    if(newrow==destination.first&&newcol==destination.second){
                        return dist[newrow][newcol];
                    }
                    q.push({distance+1,{newrow,newcol}});
                }
            }
        }
        return -1;
        
    }
};
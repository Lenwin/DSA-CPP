// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source==destination){
            return 0;
        }
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size();
        int m = grid[0].size();
        //Distance vector initialized as infinity
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        //Making distance to source node as zero and pushing it into queue
        dist[source.first][source.second]=0;
        q.push({dist[source.first][source.second],{source.first,source.second}});
        //Vectors for traversal in 4 directions and BFS
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        while(!q.empty()){
            int distance  = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow = row+delrow[i];
                int newcol = col+delcol[i];
                //If the grid of new cell is 1 and if distance+1 is less than current smallest distance update distance
                if(newrow<n&&newrow>=0&&newcol<m&&newcol>=0&&grid[newrow][newcol]==1&&distance+1<dist[newrow][newcol]){
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

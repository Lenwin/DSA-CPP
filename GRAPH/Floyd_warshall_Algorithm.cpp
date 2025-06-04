// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
    
        //floyd Warshall
        //We find shortest path between all paths via all nodes 
        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dist[i][via]==1e8||dist[via][j]==1e8){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
      
    }
};
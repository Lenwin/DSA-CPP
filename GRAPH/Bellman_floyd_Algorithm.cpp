// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>distance(V,1e8);
        distance[src] = 0;
        //We will check if we can reach any node with distance less than previous shortest distance If yes we will update distance
        //We will repeat the steps V-1 times as in the worst case if the first reachable node is at the end of the vector "edges"e nee"
        for(int i=0;i<V-1;i++){
            for(auto i: edges){
                int u =i[0];
                int v = i[1];
                int w = i[2];
                if(distance[u]!=1e8&&distance[u]+w<distance[v]){
                    distance[v] = distance[u]+w;
                }
            }
        }
        //If there is no negative cycle we the distance value cant be updated after V-1 iterations 
        //If we are able to update it even after V-1 iterations it menas negative cycle deteected
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            if(distance[u]!=1e8&&distance[u]+w<distance[v]){
                return {-1};
            }
        }
        return distance;
    }
};

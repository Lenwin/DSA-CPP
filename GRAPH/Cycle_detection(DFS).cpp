class Solution {
  private:
    //DFS to detect cyle
    //Parameters are adjacency list vector visited src and parent 
    //Storing parent to make sure that it doesn't return true because its parent is already visited and it is adjacent to its child.
    bool dfs(vector<vector<int>> &adjacent_list,vector<int>&visited,int src,int parent){
        visited[src] = 1;
        for(int adj:adjacent_list[src]){
            if(!visited[adj]){
                //if any of the dfs call detects cycle returns true.
               if (dfs(adjacent_list,visited,adj,src)){
                   return true;
               };
            }
            //if it is visited and its parent is nor equal  to adjacent returns true.
            //There is a case that parent of a node will be always visited and it will be adjacent to the child so returns true always
            else{
                if(adj!=parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adjacency_list(V);
        //converting edge list to adjacency list
        for(auto edge:edges){
            int u=edge[0];
            int v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
            
        }
        // Code here
        vector<int>visited(V,0);
        //Running DFS for all nodes if the graph is not connected
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adjacency_list,visited,i,-1))
                    return true;
            }
        }
        return false;
        
    }
};
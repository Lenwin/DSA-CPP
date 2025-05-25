// User function Template for C++
class Solution {
  private:
  //Topological sort function
    void toposort(int node,vector<vector<pair<int,int>>>&adj,vector<int>&visited,stack<int>&st){
        visited[node] =1;
        for(auto i:adj[node]){
            int v = i.first;
            if(!visited[v]){
                toposort(v,adj,visited,st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        //Coneverting Edges into adjacency list 
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        //Using topological sort to traverse the graph in that order
        //We can make sure that we reach that node only after its predecessors are visited
        vector<int>visited(V,0);
        stack<int>st;
        //Calling topological sort
        for(int i=0;i<V;i++){
            if(!visited[i]){
                toposort(i,adj,visited,st);
            }
        }
        //Calculating distance
        vector<int>distance(V,INT_MAX);
        distance[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto i:adj[node]){
                int v = i.first;
                int wt = i.second;
                //If the distance of the node + weight of current node is less than the current shortest distance we update them
                if(distance[node]!=INT_MAX&&distance[node]+wt<distance[v]){
                    distance[v]=distance[node]+wt;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(distance[i]==INT_MAX){
                distance[i] = -1;
            }
        }
        return distance;
    }
};

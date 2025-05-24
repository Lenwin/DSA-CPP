class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        //Queue to store the nodes in a queue for BFS 
        queue<int>q;
        //We will Push source into the queue
        q.push(src);
        //Initializing a vector to store the distance from the source to the specififc node
        //By default it has INT_MAX as value it gets updated whenever it finds a smaller distance
        vector<int>distance(adj.size(),INT_MAX);
        //Distance from source node to that node is zero 
        distance[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //If the distance from the source to node is greater than the 1+ distance from the neighbour node
            //Then we will update distance and push it into queue
            for(auto i:adj[node]){
                if(distance[i]>distance[node]+1){
                    distance[i]=distance[node]+1;
                    q.push(i);
                }
            }
        }
        //If the node is unreachable we will update its distance to -1
        for(int i=0;i<adj.size();i++){
            if(distance[i]==INT_MAX){
                distance[i] = -1;
            }
        }
        return distance;
    }
};
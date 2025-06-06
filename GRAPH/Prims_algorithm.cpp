class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        //Min heap to store the elemets with lowest weight
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //To Keep track of visited elements
        vector<int>vis(V,0);
        //We will push initial node with weight to zero into the heap
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            //We pop the first element 
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            //If it is already visited we will skip the element
            if(vis[node]==1)continue;
            //Calculating total edge weights
            sum+=weight;
            vis[node]=1;
            //We push the adjacent elements into  the heap
            for(auto i:adj[node]){
                int adjnode = i[0];
                int weight = i[1];
                if(!vis[adjnode]){
                    pq.push({weight,adjnode});
                }
            }
        }
        return sum;
        
        
    }
};
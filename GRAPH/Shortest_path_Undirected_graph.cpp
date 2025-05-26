class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        //Converting edge list into adjacency list
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        //Priority queue to store the sdistance and current node.
        //The shortest path will always be selected first
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //Distance vector to store the shortest distance
        vector<int>distance(n+1,1e9);
        //To Memorize the parent node of each node from where it reached that node
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        distance[1] = 0;
        pq.push({0,1});
        //BFS traversal
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto i:adj[node]){
                int adjnode = i.first;
                int edgeweight = i.second;
                if(dis+edgeweight<distance[adjnode]){
                    distance[adjnode]=dis+edgeweight;
                    pq.push({dis+edgeweight,adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if(distance[n]==1e9){
            return {-1};
        }
        //Reconstructing the path from the memorized array
        vector<int>path;
        int i = n;
        while(parent[i]!=i){
            path.push_back(i);
            i = parent[i];
        }
        //Pushing the source node
        path.push_back(1);
        reverse(path.begin(),path.end());
        path.insert(path.begin(),distance[n]);
        return path;
    }
};
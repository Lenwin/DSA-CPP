class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>>adj(n);
        //Converting edge list into adjacency list
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        //Priority queue for Djikstra 
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>distance(n,LLONG_MAX);
        //To store inn= how many ways we can reach each node
        //We can reach every node in more than one ways
        //That means total number of ways we can reach the next node will be equal to that node 
        vector<int>ways(n,0);
        //Implementing dJikstras algorithm
        pq.push({0,0});
        distance[0] = 0;
        ways[0]=1;
        int mod = (int)(1e9+7);
        while(!pq.empty()){
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            for(auto i:adj[node]){
                int adjnode = i.first;
                long long edw = i.second;
                //Case 1 when we are reaching a path for the first time in the shortest way
                if(edw+dist<distance[adjnode]){
                    pq.push({edw+dist,adjnode});
                    distance[adjnode] = edw+dist;
                    ways[adjnode] = ways[node];
                }
                //Case 2 we are reaching the node in a different way but in one of the shortest path
                //It will be equal to numebr of ways in which we can reach the previous node
                else if(edw+dist==distance[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        //Returning the number of ways in which we can reach the destination
        return ways[n-1]%mod;
    }
};
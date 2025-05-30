class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        //Converting flights to adjacency list
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        //Queue to store hops source and price
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        //Storing the shortest distance
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        while(!q.empty()){
            int hops=q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();
            //If number of hops is greater than k it should skip that in the queue
            if(hops>k)continue;
            for(auto it:adj[node]){
                int adjnode = it.first;
                int price = it.second;
                if(dist+price<distance[adjnode]){
                    distance[adjnode] = dist+price;
                    q.push({hops+1,{adjnode,dist+price}});
                }
            }
        }
        if(distance[dst]==INT_MAX){
            return -1;
        }
        return distance[dst];
    }
};
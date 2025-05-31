class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Creating a adjacency list
        //Conerting it into zero indexed
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:times){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u-1].push_back({v-1,w});
        }
        vector<int>distance(n,INT_MAX);
        //Priority queue so that the closest node is processed first
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //Pushing source into queue 
        //Converting it to zero indexed array
        pq.push({0,k-1});
        distance[k-1] = 0;
        //Implementing djikstra
        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(auto &i:adj[node]){
                int adjnode = i.first;
                int adtime = i.second;
                if(time+adtime<distance[adjnode]){
                    pq.push({time+adtime,adjnode});
                    distance[adjnode]= time+adtime;
                }
            }
        }
        //The maximum time taken to reach any node will be the minimum time taken to reach all nodes
        //If any of the node is unreachable returning -1
        int maxi = 0;
        for(int i=0;i<distance.size();i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            maxi = max(maxi,distance[i]);
        }
        return maxi;
        
    }
};
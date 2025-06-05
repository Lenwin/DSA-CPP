class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Creating distance matrix from thr edges
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        //Distance to same node is 0
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        //Floyd warshall algorithm to find distance between all cities
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]==INT_MAX||dist[via][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j]= min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        //Finding the city with the smallest number of neighbor att threshold distance
        int city = -1;
        int mincount=INT_MAX;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mincount){
                city = i;
                mincount = count;
            }
        }
        return city;
    }
};
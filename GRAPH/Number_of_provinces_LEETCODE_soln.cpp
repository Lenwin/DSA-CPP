class Solution {
private:
    //DFS of a the graph
    void dfs(int node,vector<vector<int>>adjacencylist,vector<int> &visited){
        visited[node]=1;
        for(int i:adjacencylist[node]){
            if(!visited[i]){
            dfs(i,adjacencylist,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //finding number of vertices
        int n = isConnected.size();
        //for converting adjacency matrix to adjacency list
        vector<vector<int>>adjacencylist(n);
        //traversing through the matrix and converting it  into adjacency list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjacencylist[i].push_back(j);
                    adjacencylist[j].push_back(i);
                }
            }
        }
        //To keep track of visited nodes
        vector<int>visited(n,0);
        int count=0;
        //Calling DFS for all nodes if it is  Not visited
        //If all nodes are connected We will call dfs only once from here and the rest will be recursively called
        //If there are multiple provinces we will call dfs from here whenever there is a new unvisited node
        for(int i=0;i<n;i++){
            if(!visited[i]){
                //Keep tracks of number of provinces
                count++;
                dfs(i,adjacencylist,visited);
            }
        }
        return count;
        
    }
};
class Solution{
    private:
        //Using BFS to detect cycle
        bool detect(vector<int>adj[],int src,vector<int>&visited){
            //Queue contains a pair where the first one is the node and second one is the parent of the node from where the node arrivedd
            queue<pair<int,int>> q;
            //Pushing the source into queue and made its parent -1 as it is the starting 
            visited[src] = 1;
            q.push({src,-1});
            while(!q.empty()){
                //The node which we are currently in
                int current = q.front().first;
                //The node from where we reached the node
                int parent = q.front().second;
                q.pop();
                //For adjacent nodes checking if they are visited
                //If they are not visited we will push adjacent node and current node as pair
                //The node from where it reached will be adjacent and it will be visited so we use the previous statement(It will be always true) To solve this we
                //Check if the node from where it reached is same as adjacent if not we will return true
                for(int adjacent:adj[current]){
                    if(!visited[adjacent]){
                        visited[adjacent]=1;
                        q.push({adjacent,current});
                    }
                    else{
                        if(parent!=adjacent){
                            return true;
                        }
                    }
                }
            }
            return false;
    
            
    
        }
    public:
        bool isCycle(int V, vector<int> adj[]) {
            vector<int>visited(V,0);
            //To make sure that all nodes are visited if the graph nodes are not connected
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    if(detect(adj,i,visited)){
                        return true;
                    }
                }
            }
            return false;
    
            
        }
    };
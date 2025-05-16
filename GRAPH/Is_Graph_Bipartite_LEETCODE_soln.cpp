class Solution {
private:
    bool dfs(int node,int color,vector<int>&colour,vector<vector<int>>&graph){
        //Giving color to the node
        colour[node]=color;
        //Giving an opposite colour to all its adjacent nodes
        for(int i:graph[node]){
            if(colour[i]==-1){
                if(dfs(i,!color,colour,graph)==false){
                    return false;
                }
            }
            //If any of the adjacent node has same color as that of its parent returns false
            else if(colour[i]==color){
                    return false;
            }

        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //Initializing a vector to store the color of adjacent nodes.Initialized as -1
        vector<int>colour(n,-1);
        //Graph maybe disconnected so making sure that every node is traversed
        for(int i=0;i<n;i++){
            //If colour[i] is -1 it means it is not visited
            if(colour[i]==-1){
                //Calling DFS if it returns false it is false
                if(dfs(i,0,colour,graph)==false){
                    return false;
                }

            }
        }
        return true;
        
    }
};
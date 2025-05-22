class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Creating a Graph by reversing the edge direction
        //And calculating the indegree afterwards 
        //The terminal nodes are always safe so we should start our topological sort from terminal nodes
        int V = graph.size();
        vector<vector<int>>rev(V);
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto j:graph[i]){
                rev[j].push_back(i);
                indegree[i]++;
            }
        }
        //Topological sort of the node we will push the node if indegree is zero
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //BFS traversal
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            //We will reduce the indegree of all adjacent nodes if it is zero we will push into the queue
            for(auto i:rev[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
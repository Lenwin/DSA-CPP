class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        //Lets consider Tasks as a node of graph and prerequisites contains the edges between them
        //we are converting the edge list into an adjacency list
        for(auto i:prerequisites){
            adj_list[i[1]].push_back(i[0]);
        }
        //Finding indegree of all nodes
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto j:adj_list[i]){
                indegree[j]++;
            }
        }
        //Finding the order using topological sort
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            //For all elements if indegree is zero we will push it into the queue
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //BFS traversal of graph
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj_list[node]){
                //We will reduce the indegree of all adjaecent nodes of current node
                indegree[i]--;
                //If equal to zero we will push into queue
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            
        }
        //returning the topological sort if there is no cycle 
        //If size of topological sort is equal to number of courses no cycle
        //Else returning empty array
        if(ans.size()==numCourses){
            return ans;
        }
        return {};

        
    }
};
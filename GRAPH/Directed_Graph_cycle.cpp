//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //Converting Edgelist to adjacency list
        vector<vector<int>>adj_list(V);
        for(auto i:edges){
            adj_list[i[0]].push_back(i[1]);
        }
        //Counting Indegree of each and every node
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj_list[i]){
                indegree[j]++;
            }
        }
        //BFS traversal on graph
        //If any of the graph has an indegree of zero it should come first in topological sort so pushing into the queue
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //Counting the number of elements in the topological sort 
        //If it is less than number of elements it contains a cycle
        //If it is equal to the number of elements it doesnt have any cycle
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(int i:adj_list[node]){
                //reducing indegree of all adjacent nodes of the current node 
                //if it is zero push into queue
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(cnt==V){
            return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    void dfs(int node,stack<int>&st,vector<int>&visited,vector<vector<int>>&adj_list){
        visited[node]=1;
        //Calling DFS for all its adjacent nodes
        for(auto i:adj_list[node]){
            if(!visited[i]){
                dfs(node,st,visited,adj_list);
            }
        }
        //If all its DFS calls are over we will push it into the stack
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj_list(V);
        //converting edges into adjacency list
        for(auto i:edges){
            adj_list[i[0]].push_back(i[1]);
        }
        vector<int>visited(V,0);
        //Stack to store the lements that finished DFS calls
        stack<int>st;
        vector<int>ans;
        //Calling DFS for all nodes if they are not visited
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,st,visited,adj_list);
            }
        }
        //Poping elements from the stack so that we will get the list in reverse order of how the dfs calls ended
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
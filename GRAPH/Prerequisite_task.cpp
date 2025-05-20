//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>>adj_list(N);
        //Converting Edge list into adjacency list
        for(auto i:prerequisites){
            adj_list[i.first].push_back(i.second);
        }
        //Counting indegree of all nodes
        vector<int>indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto j:adj_list[i]){
                indegree[j]++;
            }
        }
        //Finding topological sort of the graph rt
        //Finding all nodes with degree 0 it means it is the first in the topological so
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // for Counting number of elemnts in topological sort
        //BFS to find topological sort
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int i:adj_list[node]){
                //Reducing indegree of all its adjacent elememnts
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        //If count is equal to Number of tasks it means all task can be executed
        //Else some tasks cannot be executed
        if(count==N){
            return true;
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
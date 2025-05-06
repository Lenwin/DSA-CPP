#include<bits/stdc++.h>
using namespace std;
class Graph{
    //Adjacency list of the graph to store edges
    vector<vector<int>>adj_list;
    int V;
private:
    //creating a helper function for previous call
    void dfs(int current,vector<int>&visited){
        //marking the current node as visited
        visited[current]=1;
        //printing the output
        cout<<current<<"->";
        //Calling dfs recursively for unvisited node
        for(int i:adj_list[current]){
            if(!visited[i]){
                dfs(i,visited);
            }
        }
    }
public:
    //Constructor will initialize the number of vertices and resizes the adjacency list
    Graph(int n){
        int V = n;
        adj_list.resize(V);
    }
    //Function to add edges to the list
    void add_edge(int u,int v){
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }//Function to call DFS of the graph
    void DFS(){
        //initialized a vector to track the visited elements
        vector<int> visited(V,0);
        int start = 0;
        //calling the helper function
        dfs(start,visited);
    }

};
int main(){
    //Declaring a graph with 4 vertices
    Graph g(7);

    //adding edges into adjacency list
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(2,5);
    g.add_edge(2,6);

    //DFS traversal of the graph
    g.DFS();

    return 0;
}
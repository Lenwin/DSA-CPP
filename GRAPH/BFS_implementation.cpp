#include<bits/stdc++.h>
using namespace std;
class Graph{
    //Adjacency list of the graph to store edges
    vector<vector<int>>adj_list;
    int V;
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
    }
    void BFS(int start){
        //initializing the size, Array to check if it is visited or not and a queue to do bfs.
        int n = adj_list.size();
        vector<bool>visited(n,0);
        queue<int>q;
        //pushing the starting vertices to the queue
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            //Taking the first element and printing it 
            int current = q.front();
            cout<<current<<"->";
            q.pop();
            //adding the adjacent elements of the current vertex to the queue to do BFS
            for(int neighbour:adj_list[current]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);

                }
            }
        }
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

    //BFS traversal starting from 0
    g.BFS(0);

    return 0;
}
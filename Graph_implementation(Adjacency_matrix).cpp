#include<bits/stdc++.h>
using namespace std;
class Graph{
    //Adjacency Matrix of the graph to store edges
    vector<vector<int>>adj_matrix;
public:
    //Constructor to create a square matrix of size n with initial value 0
    Graph(int n){
        adj_matrix = vector<vector<int>>(n,vector<int>(n,0));
    }
    //Function to add edges to the matrix
    void add_edge(int u,int v){
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    //Function to display the adjacency matrix of Graph
    void display_matrix(){
        int n = adj_matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<adj_matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

};
int main(){
    //Declaring a graph with 4 vertices
    Graph g(4);

    //adding edges into adjacency matrix
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,0);

    //Displaying Adjacent Matrix of that Graph
    g.display_matrix();

    return 0;
}
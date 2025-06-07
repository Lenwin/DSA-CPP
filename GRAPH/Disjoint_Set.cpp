#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    //Rank is the depth of the graph from the node
    //Parent is the parent of the node
    vector<int>rank,parent,size;
public:
    //Constructor to initialize set
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        //By default the parent of a node is itself
        for(int i=0;i<n+1;i++){
            parent[i]=i;
            size[i] = 1;
        }
    }
    //Finding ultimate parent of a node
    int findUp(int node){
        //if a parent of node is itself it is the ultimate node
        if(node==parent[node]){
            return node;
        }
        //Recursively reaching the ultimate parent
        //We also compress the ultimate parent in every step
        return parent[node] = findUp(parent[node]);
    }
    //Union by rank
    void unionByRank(int u,int v){
        //Finding ultimate parent of both the nodes
        int ulp_u = findUp(u);
        int ulp_v = findUp(v);
        //If they are equal we will just skip(nothing to be done)
        if(ulp_u==ulp_v)return;
        //We will attach the graph with lesser rank to the graph with higher rank 
        //For that we will change its ultimate parent to the one with higher rank
        //Increase rank 
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    //Union by size
    void unionBySize(int u,int v){
        int ulp_u = findUp(u);
        int ulp_v = findUp(v);
        if(ulp_u==ulp_v)return;
        //We will attach the graph to one with larger size to reduce the height of the grpah
        //We will update ultimate power of smaller graph with ultimate power of larger graph
        //Update size by adding both
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }

    }


};
int main(){
    //Creating a disjoint graph
    DisjointSet ds(7),ds2(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(3,4);
    ds.unionByRank(5,6);
    ds.unionByRank(6,7);
    //Before Connecting graph it shows they are different
    if(ds.findUp(3)==ds.findUp(6)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }
    ds.unionByRank(3,7);
    //After connecting it shows that they are same
    if(ds.findUp(3)==ds.findUp(6)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }
    ds2.unionBySize(1,2);
    ds2.unionBySize(2,3);
    ds2.unionBySize(3,4);
    ds2.unionBySize(5,6);
    ds2.unionBySize(6,7);
    //Before Connecting graph it shows they are different
    if(ds2.findUp(3)==ds2.findUp(6)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }
    ds2.unionBySize(3,7);
    //After connecting it shows that they are same
    if(ds2.findUp(3)==ds2.findUp(6)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }
    return 0;
}
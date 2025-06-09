class DisjointSet{
public:
    //Rank is the depth of the graph from the node
    //Parent is the parent of the node
    vector<int>rank,parent,size;
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
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //We will create a disjoint set with n nodes
        DisjointSet ds(n);
        //We will count number of extra edges in the graph
        //While traversing if we find an edge where they already have same ultimate parent they are extra edge
        int extraedges = 0;
        for(auto i:connections){
            if(ds.findUp(i[0])!=ds.findUp(i[1])){
                ds.unionBySize(i[0],i[1]);
            }
            else{
                extraedges++;
            }
        }
        //We will count number of unconnected components in the graph
        //If parent[i] is equal to i in parent array it means it is a component
        //The count of this will give number of unconnected components in the graph
        //The minimum number of edges required to connect the grpah is ewual to components-1
        int components = 0;
        for(int i=0;i<n;i++){
            if(i==ds.parent[i]){
                components++;
            }
        }
        //If extra edges are greater than components-1 we eill return answer else return -1
        if(extraedges>=components-1){
            return components-1;
        }
        return -1;
    }
};
// User function Template for C++
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
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        //We will convert it into a vector with three elements with first element as weight so that we can sort it according to its weights
        vector<pair<int,pair<int,int>>>edge_list;
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            edge_list.push_back({w,{u,v}});
        }
        //We will create a disjoint set for the graph 
        DisjointSet ds(V);
        //Sorting accoriding to its weights
        sort(edge_list.begin(),edge_list.end());
        int mst = 0;
        //For all edges if a path doesnt exist between two
        //ie the ultimate parent should be different and it eill be part of a single graph
        //We will add it into graph ans add its weight
        for(auto i:edge_list){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            if(ds.findUp(u)!=ds.findUp(v)){
                ds.unionBySize(u,v);
                mst+=wt;
            }
        }
        
        return mst;
    }
};
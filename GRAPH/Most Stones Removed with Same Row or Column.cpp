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
    int removeStones(vector<vector<int>>& stones) {
        //FInding the highest row and col in the graph 
        int maxrow = 0;
        int maxcol = 0;
        int n = stones.size();
        for(auto it :stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        unordered_map<int,int>stoneNodes;
        //Creating  a disjoint set with maxrow+maxcol+1
        //Converting the columns into maxrow+column number so that we can make them into single graph
        DisjointSet ds(maxrow+maxcol+1);
        for(auto it:stones){
            int noderow = it[0];
            int nodecol = it[1]+maxrow+1;
            ds.unionBySize(noderow,nodecol);
            //Counting Number of stones left
            //If the column is used that means the there is a stone in that row and similarly for column also
            //We just need to count one time for single parent
            stoneNodes[noderow]=1;
            stoneNodes[nodecol]=1;
        }
        int cnt = 0;
        //we will count total number of stones also
        for(auto it:stoneNodes){
            if(ds.findUp(it.first)==it.first){
                cnt++;
            }
        }
        //The returning the number of stones removed
        return n-cnt;
    }
};
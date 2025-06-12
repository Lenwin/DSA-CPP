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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        //Matrix to keep track of visited nodes 
        vector<vector<int>>vis(n,vector<int>(m,0));
        //Disjoint graph of size n*m
        DisjointSet ds(n*m);
        //FOr counting number of islands
        int cnt =0;
        //For storing the count after each operation
        vector<int>ans;
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            //If its already visited we dont need to do anything so we can directly insert count
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            //Otherwise we will make it visited and increase count
            vis[row][col]=1;
            cnt++;
            //For traversing in 4 directions
            vector<int>delrow = {-1,0,1,0};
            vector<int>delcol = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjrow = row+delrow[i];
                int adjcol = col+delcol[i];
                if(adjrow<n&&adjrow>=0&&adjcol<m&&adjcol>=0){
                    //If adjacent node is already visited and their ultimate parent is differnet we will join them and decrease island count by
                    if(vis[adjrow][adjcol]==1){
                        int nodenum = row*m+col;
                        int adjnodenum = adjrow*m+adjcol;
                        if(ds.findUp(nodenum)!=ds.findUp(adjnodenum)){
                            cnt--;
                            ds.unionBySize(nodenum,adjnodenum);
                        }
                        
                    }
                }
            }
            ans.push_back(cnt);
            
        }
        return ans;
    }
};

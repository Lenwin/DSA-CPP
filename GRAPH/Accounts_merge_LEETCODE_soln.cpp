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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        //Creating a disjint set of n elements
        DisjointSet ds(n);
        //Unordered map to store the mail and the node which was found
        unordered_map<string,int> mapmailnode;
        //For all mails in accounts if the mail doesn exist in map we will make it one if it already exists we will connect both the nodes
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end()){
                    mapmailnode[mail] = i;
                }
                else{
                    ds.unionBySize(i,mapmailnode[mail]);
                }
            }
        }
        //We will merge all the nodes according to the map
        vector<vector<string>>mergedmail(n);
        for(auto it:mapmailnode){
            string mail = it.first;
            int node = ds.findUp(it.second);
            mergedmail[node].push_back(mail);
        }
        //We will sort the mails and push it to ans and returm
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedmail[i].size()==0)continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
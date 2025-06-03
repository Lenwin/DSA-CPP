// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end){
            return 0;
        }
        //Creating  a graph with 9999 nodes because of modulo operator
        vector<int>distance(99999,INT_MAX);
        //Implementing simple djikstra where the adjacent nodes of  a node is the product od node with elements in array
        queue<pair<int,int>>q;
        q.push({start,0});
        distance[start]=0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto i:arr){
                int adjnode = (node*i)%100000;
                if(steps+1<distance[adjnode]){
                    distance[adjnode] = steps+1;
                    //If we reacj end we will return steps
                    if(adjnode==end){
                        return steps+1;
                    }
                    q.push({adjnode,steps+1});
                }
            }
        }
        return -1;
        
    }
};

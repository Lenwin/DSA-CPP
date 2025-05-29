class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        //Priority Queue to implement djikstra in the graph
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>diff(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        diff[0][0] = 0;
        //BFS traversal on the graph
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        while(!pq.empty()){
            int difference = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            //If we reach destination return diffrenece as the smallest value will be in top of priority queue
            if(row==n-1&&col==m-1){
                return difference;
            }
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                    //Checking difference between heights of adjacent cells
                    int newdiff = max(abs(heights[nrow][ncol]-heights[row][col]),difference);
                    //If effort is less than previous differnece we will update and push
                    if(newdiff<diff[nrow][ncol]){
                        diff[nrow][ncol] = newdiff;
                        pq.push({newdiff,{nrow,ncol}});
                    }

                }
            }
        }
        return 0;  
    }
};
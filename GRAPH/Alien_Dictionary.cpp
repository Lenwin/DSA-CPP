class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        //Adjacency List for 26 alphabets
        //marking the alphabets present in the dictionary
        //Vector to calculate indegree of all alphabets
        vector<vector<int>>adj(26);
        vector<int>present(26);
        vector<int>indegree(26);
        //CHecking if the alphabet is present or not
        for(int i=0;i<words.size();i++){
            string word = words[i];
            for(int j=0;j<word.size();j++){
                present[word[j]-'a'] = 1;
            }
        }
        //Comparing the adjacent words to find the alphabet precedence
        for(int i=0;i<words.size()-1;i++)
        {
            string s1 = words[i];
            string s2 = words[i+1];
            //Finding the minimum of length between two strings
            int len = min(s1.length(),s2.length());
            if (s1.substr(0, len) == s2.substr(0, len) && s1.length() > s2.length()) {
                return "";
            }
            //Comparing two strings alphabets if they are not equal we create a graph with an edge from the alphabet with greater precedence to lower one
            //we also calculate the indegree of nodes 
            //If any of the alphabets in same position are not equal there is no further need of comparison so break
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                    break;
                }
            }
        }
        //Queue for BFS traversal (Kahns Algortithm)
        queue<int>q;
        //If the alphabet is present in the dictionary and its indegree is zero we push it into the queue 
        for(int i=0;i<26;i++){
            if(indegree[i]==0&&present[i]==1){
                q.push(i);
            }
        }
        //Toological sort on the graph and we build the answer by converting it back into alphabet
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(char(node+'a'));
            for(auto c:adj[node]){
                //We refduce indegree of all adjacent nodes
                indegree[c]--;
                //If indegree becomes zero we push into the queue
                if(indegree[c]==0){
                    q.push(c);
                }
            }
            
        }
        //For any alphabet has indegree greater than zero after topo sort it means there is a cycle
        for(int i=0;i<26;i++){
            if(present[i]==1&&indegree[i]!=0){
                return "";
            }
        }
        return ans;
    }
};